//网络初始化

#include<THREAD_POOL.h>


int thread_pool_net_init()
{
	struct sockaddr_in serveraddr;
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family =AF_INET;
	serveraddr.sin_port=htons(SERVER_PORT);
	inet_pton(AF_INET,SERVER_IP,&serveraddr.sin_addr.s_addr);
	int sockfd;
	sockfd = SOCKET(AF_INET,SOCK_STREAM,0);
	BIND(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	LISTEN(sockfd,BACKLOG);
	printf("[1] Thread Pool Server init net successly serverfd = %d..\n",sockfd);

	return sockfd;
}

