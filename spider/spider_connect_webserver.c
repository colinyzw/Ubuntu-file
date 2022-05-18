#include <spider.h>

int spider_connect_webserver(int sockfd,url_t* node)
{
	//构造服务端的网络信息
	struct sockaddr_in webserver;
	webserver.sin_family = AF_INET;
	webserver.sin_port = htons(node->port);
	inet_pton(AF_INET,node->ip,&webserver.sin_addr.s_addr);

	if((connect(sockfd,(struct sockaddr*)&webserver,sizeof(webserver)))==-1)
	{
		perror("spider_connect_webserver >> connect call failed");
		exit(0);
	}
	printf("<<spider step 3>>connect webserver success..\n");

	return 0;
}
