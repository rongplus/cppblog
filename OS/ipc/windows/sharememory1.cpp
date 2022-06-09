#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>

#define BUF_SIZE 256
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");
TCHAR szMsg[]=TEXT("Message from first process.");
BOOL SetPrivilege(
    HANDLE hToken,          // access token handle
    LPCTSTR lpszPrivilege,  // name of privilege to enable/disable
    BOOL bEnablePrivilege   // to enable or disable privilege
    ) 
{
    TOKEN_PRIVILEGES tp;
    LUID luid;

    if ( !LookupPrivilegeValue( 
            NULL,            // lookup privilege on local system
            lpszPrivilege,   // privilege to lookup 
            &luid ) )        // receives LUID of privilege
    {
        printf("LookupPrivilegeValue error: %u\n", GetLastError() ); 
        return FALSE; 
    }

    tp.PrivilegeCount = 1;
    tp.Privileges[0].Luid = luid;
    if (bEnablePrivilege)
        tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    else
        tp.Privileges[0].Attributes = 0;

    // Enable the privilege or disable all privileges.

    if ( !AdjustTokenPrivileges(
           hToken, 
           FALSE, 
           &tp, 
           sizeof(TOKEN_PRIVILEGES), 
           (PTOKEN_PRIVILEGES) NULL, 
           (PDWORD) NULL) )
    { 
          printf("AdjustTokenPrivileges error: %u\n", GetLastError() ); 
          return FALSE; 
    } 

    if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)

    {
          printf("The token does not have the specified privilege. \n");
          return FALSE;
    } 

    return TRUE;
}

BOOL EnablePrivilege()
{
    LUID PrivilegeRequired ;
    DWORD dwLen = 0, iCount = 0;
    BOOL bRes = FALSE;
    HANDLE hToken = NULL;
    BYTE *pBuffer = NULL;
    TOKEN_PRIVILEGES* pPrivs = NULL;

    bRes = LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &PrivilegeRequired);
    if( !bRes) return FALSE;
    
    bRes = OpenThreadToken(GetCurrentThread(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, TRUE, &hToken); 
    if(!bRes) return FALSE;

    bRes = GetTokenInformation(hToken, TokenPrivileges, NULL, 0, &dwLen);
    if (TRUE == bRes)
    {
        CloseHandle(hToken);
        return FALSE;
    }
    pBuffer = (BYTE *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwLen);
    if(NULL == pBuffer) return FALSE;
    
    if (!GetTokenInformation(hToken, TokenPrivileges, pBuffer, dwLen, &dwLen)) 
    {
        CloseHandle(hToken);
        HeapFree(GetProcessHeap(), 0, pBuffer);
        return FALSE;
    }

    // Iterate through all the privileges and enable the one required
    bRes = FALSE;
    pPrivs = (TOKEN_PRIVILEGES*)pBuffer;
    for(iCount = 0; iCount < pPrivs->PrivilegeCount; iCount++)
    {
        if (pPrivs->Privileges[iCount].Luid.LowPart == PrivilegeRequired.LowPart &&
          pPrivs->Privileges[iCount].Luid.HighPart == PrivilegeRequired.HighPart )
        {
            pPrivs->Privileges[iCount].Attributes |= SE_PRIVILEGE_ENABLED;
            // here it's found
            bRes = AdjustTokenPrivileges(hToken, FALSE, pPrivs, dwLen, NULL, NULL);
            break;
        }
    }

    CloseHandle(hToken);
    HeapFree(GetProcessHeap(), 0, pBuffer);    
    return bRes;
}

int _tmain()
{
    LPCTSTR PrivilegeRequired;
    HANDLE hToken = NULL;
    bool bRes = OpenThreadToken(GetCurrentThread(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, TRUE, &hToken); 
    if(!bRes) 
    {
        std::cout << "Error to open handle" << std::endl;
        return 0;
    }
    if (!SetPrivilege(hToken,PrivilegeRequired,true))
    {
        std::cout << "Error to SetPrivilege" << std::endl;
        return 0;
    }

    if (!EnablePrivilege())
    {
        std::cout << "Error to enable privilege" << std::endl;
        return 0;
    }
   HANDLE hMapFile;
   LPCTSTR pBuf;

   hMapFile = CreateFileMapping(
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD)
                 BUF_SIZE,                // maximum object size (low-order DWORD)
                 szName);                 // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not create file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }
   pBuf = (LPTSTR) MapViewOfFile(hMapFile,   // handle to map object
                        FILE_MAP_ALL_ACCESS, // read/write permission
                        0,
                        0,
                        BUF_SIZE);

   if (pBuf == NULL)
   {
      _tprintf(TEXT("Could not map view of file (%d).\n"),
             GetLastError());

       CloseHandle(hMapFile);

      return 1;
   }


   CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
    _getch();

   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);

   return 0;
}