
#include <windows.h>
#include <stdio.h>
 
void RunExe()
{
	STARTUPINFO stStartUpInfo;
	::memset(&stStartUpInfo, 0 ,sizeof(stStartUpInfo));
	stStartUpInfo.cb = sizeof(stStartUpInfo);
 
	PROCESS_INFORMATION stProcessInfo;
	::memset(&stProcessInfo, 0 ,sizeof(stProcessInfo));
 
	TCHAR szPath[] = "c:\\program files\\internet explorer\\iexplore.exe";
	TCHAR szCmd[] = " http://community.csdn.net/";   //lpCommandLine的内容中开头需要一个空格，不然就和lpApplicationName连在一起去了
	try
	{
		bool bRet = ::CreateProcess(
			szPath,
			szCmd,
			NULL,
			NULL,
			false,
			CREATE_NEW_CONSOLE,
			NULL,
			NULL,
			&stStartUpInfo,
			&stProcessInfo);
 
		if (bRet)
		{
			//等待3s后关闭进程
			WaitForSingleObject(stProcessInfo.hProcess,3000L);
			::CloseHandle(stProcessInfo.hProcess);
			::CloseHandle(stProcessInfo.hThread);
			stProcessInfo.hProcess = NULL;
			stProcessInfo.hThread = NULL;
			stProcessInfo.dwProcessId = 0;
			stProcessInfo.dwThreadId = 0;
		}
		else
		{
			//如果创建进程失败，查看错误码
			DWORD dwErrCode = GetLastError();
			printf_s("ErrCode : %d\n",dwErrCode);
 
		}
	}
	catch( ... )
	{
	}
}
 
int main(int argc, char* argv[])   
{   
	RunExe();
 
	system("pause");
	return 0;   
}   