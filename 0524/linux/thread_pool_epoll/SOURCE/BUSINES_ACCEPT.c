//连接业务
#include<THREAD_POOL.h>

void *BUSINES_ACCEPT(void *arg) //传过去的是sockfd
{
	struct epoll_event node; //用于将clientfd添加到监听树上创建的节点

	int serverfd;
	serverfd = *(int*)arg;

	int clientfd;
	struct sockaddr_in clientaddr;
	socklen_t addrlen;
	addrlen = sizeof(clientaddr);

	char ip[IPSIZE];
	bzero(ip,IPSIZE);
	int flags;

	if((clientfd = ACCEPT(serverfd,(struct sockaddr *)&clientaddr ,&addrlen))>0){ //连接成功需要将clientfd添加到监听树上
		flags = fcntl(clientfd,F_GETFL,NULL);  
		fcntl(clientfd,F_SETFL,flags|O_NONBLOCK);

		printf("CUSTOMER EXEC BUSINES_ACCEPT CONNECTTION SUCCESS CLIENT[%s][%d] clientfd[%d]\n",
			inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,ip,IPSIZE),ntohs(clientaddr.sin_port),clientfd);

		node.data.fd = clientfd;
		node.events = EPOLLIN|EPOLLET; //监听读事件 
		if((epoll_ctl(epfd,EPOLL_CTL_ADD,clientfd,&node))==-1) //epfd定义为全局  //连接成功需要将clientfd添加到监听树上
			thread_pool_error("BUSINES_ACCEPT epoll_call failed",-1,FALSE);
	}

	return NULL;
}
