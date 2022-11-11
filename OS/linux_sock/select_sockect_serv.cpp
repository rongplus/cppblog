#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<Windows.h>
#include<WinSock2.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#pragma comment(lib,"ws2_32.lib") //windows socket2 32的lib库
 
 
enum CMD  //消息枚举
{
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGINOUT,
	CMD_LOGOUT_RESULT,
	CMD_ERROR
};
//消息头
struct DataHeader
{
	short dataLength;    //数据长度 32767字节
	short cmd;
};
 
struct Login : public DataHeader
{
	Login()
	{
		dataLength = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char userName[32];
	char Password[32];
};
struct Logout :public DataHeader
{
	Logout()
	{
		dataLength = sizeof(Logout);
		cmd = CMD_LOGINOUT;
	}
	char userName[32];
};
struct LoginResult :public DataHeader
{
	LoginResult()
	{
		dataLength = sizeof(LoginResult);
		cmd = CMD_LOGIN_RESULT;
	}
	int result;
};
struct LogoutResult :public DataHeader
{
	LogoutResult()
	{
		dataLength = sizeof(LogoutResult);
		cmd = CMD_LOGOUT_RESULT;
	}
	int result;
};
 
int processor(SOCKET _cSocket)
{
	//使用一个缓冲区接收数据 暂定最大收发1024个字节		后续会改进大文件的传输
	char* szRecv = new char[1024];
 
	//5 首先接收数据包头
	int nlen = recv(_cSocket, szRecv, sizeof(DataHeader), 0); //接受客户端的数据 第一个参数应该是客户端的socket对象
 
	if (nlen <= 0)
	{
		//客户端退出
		cout << "客户端已退出，任务结束" << endl;
		return -1;
	}
	//用一个指针指向这个头部
	DataHeader* header = (DataHeader*)szRecv;
	switch (header->cmd)
	{
	case CMD_LOGIN:
	{
		Login* _login;
		//读取Header->dataLength的数据长度  将数据继续读入saRecv这个块里面
		recv(_cSocket, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		_login = (Login*)szRecv;
		cout << "收到命令：CMD_LOGIN" << " 数据长度 = " << header->dataLength << " UserName = " << _login->userName << " Password = " << _login->Password << endl;
		//忽略了判断用户名密码是否正确的过程
		LoginResult _loginres;
		_loginres.result = 200;
		send(_cSocket, (char*)&_loginres, sizeof(LoginResult), 0);
	}break;
	case CMD_LOGINOUT:
	{
		Logout* _logout;
		recv(_cSocket, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		_logout = (Logout*)szRecv;
		cout << "收到命令：CMD_LOGOUT" << " 数据长度 = " << header->dataLength << " UserName = " << _logout->userName << endl;
		LogoutResult _logoutres;
		_logoutres.result = 200;
		send(_cSocket, (char*)&_logoutres, sizeof(LogoutResult), 0);
	}break;
	default:
	{
		header->cmd = CMD_ERROR;
		header->dataLength = 0;
		send(_cSocket, (char*)&header, sizeof(DataHeader), 0);
	}
	break;
	}
}
 
 
std::vector<SOCKET>g_clinets;
 
int main()
{
	//启动 windows socket 2.x 环境
	WORD versionCode = MAKEWORD(2, 2);	//创建一个版本号 
	WSADATA data;
	WSAStartup(versionCode, &data);  //启动Socket网络API的函数
									 ///
 
 
	//(1) 用Socket API建立简易的TCP服务端
 
	//	1. 建立一个Socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // ipv4 面向字节流的 tcp协议
 
	//	2. 绑定接受客户端连接的端口 bind
 
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567); //端口号 host to net  sockaddr_in中port是USHORT类型
								 //网络中port是 unsigend short类型 因此需要Htons进行转换
	//_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //服务器绑定的IP地址  127.0.0.1是本地地址
	_sin.sin_addr.S_un.S_addr = INADDR_ANY; //不限定访问该服务端的IP
	if (bind(_sock, (sockaddr*)&_sin, sizeof(_sin)) == SOCKET_ERROR)  //sockaddr 不利于编码  
	{
		cout << "ERROR: 绑定用于接受客户端连接的网络端口失败..." << endl;
	}
	else
	{
		cout << "SUCCESS: 绑定端口成功..." << endl;
	}
	//	3. 监听网络端口 listen
 
	if (listen(_sock, 5) == SOCKET_ERROR)//第二个参数 backbag 最大允许连接数量
	{
		cout << "ERROR: 监听用于接受客户端连接的网络端口失败..." << endl;
	}
	else
	{
		cout << "SUCCESS: 监听端口成功..." << endl;
	}
	
	while (true)
	{
		fd_set fdRead;
		fd_set fdWrite;
		fd_set fdExpect;
 
		FD_ZERO(&fdRead);		//清空fd集合的数据
		FD_ZERO(&fdWrite);
		FD_ZERO(&fdExpect);
		//这个宏的功能是 将服务端的_sock 放到fdRead这个集合中 
		//当socket在listen状态，如果已经接收一个连接请求，这个socket会被标记为可读，例如一个accept会确保不会阻塞的完成
		//对于其他的socket，可读性意味着队列中的数据适合读，当调用recv后不会阻塞。
		FD_SET(_sock, &fdRead);  //将服务端的socket放入可读列表，确保accept不阻塞
		FD_SET(_sock, &fdWrite);
		FD_SET(_sock, &fdExpect);
 
		for (size_t n = 0; n < g_clinets.size(); n++)
		{
			FD_SET(g_clinets[n], &fdRead);		//所有连入的客户端放入可读列表 保证recv不阻塞
		}
 
		//nfds第一个参数 是一个整数值 是指fd_set集合中所有socket值的范围 不是数量 
		int ret = select(_sock + 1, &fdRead, &fdWrite, &fdExpect, NULL);
		if (ret < 0)
		{
			cout << "select任务结束" << endl;
			break;
		}
		if (FD_ISSET(_sock, &fdRead))	//判断_sock是否在fdRead中
		{
			FD_CLR(_sock, &fdRead);
			//	4. 等待接受客户端连接 accept
			sockaddr_in _clientAddr = {};
			int cliendAddrLen = sizeof(_clientAddr);
			SOCKET _clientSock = INVALID_SOCKET; // 初始化无效的socket 用来存储接入的客户端
 
			_clientSock = accept(_sock, (sockaddr*)&_clientAddr, &cliendAddrLen);//当客户端接入时 会得到连入客户端的socket地址和长度
			if (INVALID_SOCKET == _clientSock) //接受到无效接入
			{
				cout << "ERROR: 接受到无效客户端SOCKET..." << endl;
			}
			else
			{
				cout << "新Client加入：" << "socket = " << _clientSock << " IP = " << inet_ntoa(_clientAddr.sin_addr) << endl;  //inet_ntoa 将ip地址转换成可读的字符串
			}
			g_clinets.push_back(_clientSock);
		}
 
		for (size_t n = 0; n < fdRead.fd_count; n++)
		{
			if (processor(fdRead.fd_array[n]) == -1)//processor函数是处理命令的逻辑 recv接到的数据并做出相应的判断和输出日志
			{
				auto it = find(g_clinets.begin(), g_clinets.end(), fdRead.fd_array[n]);
				if (it != g_clinets.end())
					g_clinets.erase(it);
			}
		}
	}
 
 
 
	//	6. 关闭socket
	closesocket(_sock);
	// 清除Windows socket环境
	WSACleanup();
	return 0;
}