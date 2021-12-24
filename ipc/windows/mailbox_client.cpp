
#include <stdio.h>

#include <Windows.h>

int main()
{
    HANDLE Mailslot;
    DWORD BytesWritten;
    char ServerName[256];
    Mailslot = CreateFile("\\\\.\\mailslot\\sample_mailslot", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (Mailslot == INVALID_HANDLE_VALUE)
    {
        printf("CreateFile failed with Error:%d/n", GetLastError());
        return -1;
    }

    if (WriteFile(Mailslot, "This is b Test!", 14, &BytesWritten, NULL) == 0)
    {
        printf("WriteFile with error:%d/n", GetLastError());
        return -1;
    }
}