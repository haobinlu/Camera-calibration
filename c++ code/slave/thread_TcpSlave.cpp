#include "thread_TcpSlave.h"

thread_Tcpslave::thread_Tcpslave() {

}

void thread_Tcpslave::run() {
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return;
	}

	//�����׽���  
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		emit TCP_status("socket error !");
		return ;
	}

	//��IP�Ͷ˿�  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		emit TCP_status("bind error !");
	}

	//��ʼ����  
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		emit TCP_status("listen error !");
		return;
	}

	//�ӻ�ѭ����������  
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	while (true)
	{
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
		if (sClient == INVALID_SOCKET)
		{
			emit TCP_status("accept error !");
			continue;
		}
		printf("���ܵ�һ�����ӣ�%s \r\n", inet_ntoa(remoteAddr.sin_addr));


		int ret = recv(sClient, revData, 255, 0);
		if (revData[0] == 'r') {
			emit TCP_status("recording");
			std::string s;
			for (int i = 0; i < 5; i++) {
				s.push_back(revData[i + 2]);
			}
			current_NO = QString::fromStdString(s);
			emit slave_record(true);
		}
		else if (revData[0] == 'd') {
			std::string s;
			for (int i = 0; i < 5; i++) {
				s.push_back(revData[i + 2]);
			}
			current_NO = QString::fromStdString(s);
			emit slave_del(current_NO);
		}
	}
}