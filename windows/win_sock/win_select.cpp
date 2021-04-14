#include <iostream>
#include <WinSock2.h>
#include <process.h>
 
using namespace std;
 
#pragma comment(lib,"ws2_32.lib")
 
SOCKET g_sockClient[FD_SETSIZE];	//储存客户端socket
int g_nClientCount;		        //连接数
 
//初始化Socket资源
int Initialization()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR)
	{
		cout << "Faild!" << endl;
		return 0;
	}
	return 1;
}
 
unsigned __stdcall WorkThread(void* pParam)
{
	FD_SET fdRead;
 
	TIMEVAL tv;
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	char cBuf[128];
	
	while (true)
	{
		FD_ZERO(&fdRead);
		
		for (int i = 0; i < g_nClientCount; ++i)
		{
			FD_SET(g_sockClient[i], &fdRead);
		}
 
		//这位员工就是传达室老大爷啊，有快递来了他第一个知道，
		//告诉负责收快递的员工有快递来了，快点找找去吧!
		int nRet = select(0, &fdRead, NULL, NULL, &tv);
 
		if (nRet == 0)
		{
			continue;
		}
 
		//从一大堆快递存放区中挨个儿找快递
		for (int i = 0; i < g_nClientCount; ++ i)
		{
			//终于找到了!
			if (FD_ISSET(g_sockClient[i],&fdRead))
			{
				memset(cBuf, 0, sizeof(cBuf));
				nRet = recv(g_sockClient[i], cBuf, sizeof(cBuf), 0);
				if (nRet == 0 || (nRet == SOCKET_ERROR && WSAGetLastError() == WSAECONNRESET))
				{
					closesocket(g_sockClient[i]);
					if (i < g_nClientCount - 1)
					{
						g_sockClient[i--] = g_sockClient[--g_nClientCount];
					}
				}
				cout << cBuf << endl;
				send(g_sockClient[i], cBuf, strlen(cBuf) + 1, 0);
			}
		}
	}
	return 0;
}
 
int main()
{
	if (Initialization() == 0)
	{
		return 0;
	}
 
	SOCKET sockSvr;
	SOCKADDR_IN addrSvr;
	//收发快递，要保证我们有一个收件人
	sockSvr = socket(AF_INET, SOCK_STREAM, 0);
	//收件人可以选择接受哪个地区发来的快递
	addrSvr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	//收件人可以选择接受哪种方式发来的快递(udp/tcp)
	addrSvr.sin_family = AF_INET;
	//收件人有一个固定的房间(端口)收取快递
	addrSvr.sin_port = htons(6000);
	//将收件人的各种信息告知快递商
	bind(sockSvr, (SOCKADDR*)&addrSvr, sizeof(SOCKADDR));
	//快递商留意收件人的快递
	listen(sockSvr, 5);
	std::cout << "激动的等待远方朋友的快递..." << std::endl;
 
	//成立一个新部门，专门处理快递业务
	HANDLE handle = (HANDLE)_beginthreadex(NULL, 0, &WorkThread, NULL, 0, NULL);
	CloseHandle(handle);
 
	//设立一个专门的接收快递人员,一直等待接收不同的快递
	while (true)
	{
		SOCKADDR_IN addrClient;
		int nLen = sizeof(SOCKADDR);
		SOCKET sockClient = accept(sockSvr, (SOCKADDR*)&addrClient, &nLen);
 
		if (sockClient != INVALID_SOCKET)
		{
			cout << sockClient << " connect !" << endl;
			g_sockClient[g_nClientCount] = sockClient;
			g_nClientCount++;
		}
// 		//为每个快递安排一个处理并回复人员
// 		HANDLE handle = (HANDLE)_beginthreadex(NULL, 0, &RecvThread, &sockClient, 0, NULL);
// 		CloseHandle(handle);
	}
	
	WSACleanup();
 
	system("pause");
	return 0;
}