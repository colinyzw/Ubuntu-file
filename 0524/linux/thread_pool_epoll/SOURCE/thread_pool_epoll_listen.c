//epoll监听网络事件 并向线程池中添加业务 生产者
#include<THREAD_POOL.h>
int thread_pool_epoll_listen(int epfd ,thread_pool_t* p,int sockfd) //监听树 线程池 sockfd  辨别就绪向线程池添加任务
{
	//定义就绪队列
	struct epoll_event ready_arry[EPOLLSIZE];
	int readycode; 
	busines_t bs; //业务类型

	printf("PRODUCER THREAD TID [0x%x] EPOLL LISTEN STARTING ..\n",(unsigned int)pthread_self());

	while(p->thread_shutdown){
		readycode = epoll_wait(epfd ,ready_arry,EPOLLSIZE,-1);

		while(readycode){ //添加业务
			if(ready_arry[readycode-1].data.fd == sockfd){
				bs.BUSINES_ADDR = BUSINES_ACCEPT;  //处理业务的地址  函数名
				bs.BUSINES_ARG = (void*)&ready_arry[readycode - 1].data.fd;
				thread_pool_add_busines(p,bs);
			}else{
				bs.BUSINES_ADDR = BUSINES_RESPONSE;
				bs.BUSINES_ARG = (void*)&ready_arry[readycode - 1].data.fd;
				thread_pool_add_busines(p,bs);
			}
			printf("PRODUCER THREAD TID [0x%x] ADD BUSINESS SUCCESS ...\n",(unsigned int)pthread_self());

			--readycode;
		}
	}
	return 0;
}
