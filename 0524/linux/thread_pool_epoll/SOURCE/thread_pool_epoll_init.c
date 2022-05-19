//epoll初始化
#include<THREAD_POOL.h>

int thread_pool_epoll_init(int sockfd)
{
	struct epoll_event node;
	if((epfd = epoll_create(EPOLLSIZE))== -1)
		thread_pool_error("thread_pool_epoll_init epoll call failed",-1,FALSE);

		node.data.fd = sockfd;
		node.events = EPOLLIN|EPOLLET;

		if((epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&node)) == -1)
			thread_pool_error("thread_pool_init epoll_ctl call falied",-1,FALSE);
		printf("[2] Thread Pool Server init Epoll successly epfd [%d]...\n",epfd);
		return epfd;
}
