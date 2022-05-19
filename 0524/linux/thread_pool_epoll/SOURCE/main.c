#include<THREAD_POOL.h>

int main()
{

	//服务端网络初始化
	int sockfd;
	sockfd = thread_pool_net_init();

	//EPOLL监听模型初始化
	epfd = thread_pool_epoll_init(sockfd);

	//线程池创建初始化
	thread_pool_t *pptr = NULL;
	pptr = thread_pool_create(100,10,20);

	//服务端启动业务监听
	thread_pool_epoll_listen(epfd,pptr,sockfd);

	close(sockfd);
	printf("THREAD POOL SERVER EXITING ...\n");
	return 0;
}
