//消费者 从任务队列中取任务
#include<THREAD_POOL.h>

void * thread_pool_customer_job(void * arg) //传递的参数是线程池
{
	busines_t bs;
	thread_pool_t* p = NULL;
	p = (thread_pool_t*)arg;
	pthread_detach(pthread_self());  //将该子线程的状态设置为detached,则该线程运行结束后会自动释放所有资源。
	while(p->thread_shutdown)
	{
		pthread_mutex_lock(&p->thread_lock); 
		while(p->b_cur == 0)  //没有任务 
		{
			pthread_cond_wait(&p->not_empty,&p->thread_lock); //挂起
			if(p->thread_shutdown != TRUE)
			{
				--p->thread_alive;
				pthread_mutex_unlock(&p->thread_lock);
				pthread_exit(NULL);
			}

			//缩减闲线程（这段可以先不看，看到后面就懂了）
			if(p->thread_exitcode > 0)
			{
				--p->thread_exitcode;
				--p->thread_alive;
				pthread_mutex_unlock(&p->thread_lock);
				printf("CUSTOMER THREAD [0x%x] REDUCE EXITED ...\n",(unsigned int)pthread_self());
				pthread_exit(NULL);
			}
		}

		bs.BUSINES_ADDR = p->business_queue[p->b_rear].BUSINES_ADDR;
		bs.BUSINES_ARG = p->business_queue[p->b_rear].BUSINES_ARG;
		--p->b_cur;
		p->b_rear = (p->b_rear + 1) % p->b_max; //环形偏移
		++p->thread_busy;
		pthread_mutex_unlock(&p->thread_lock);

		pthread_cond_signal(&p->not_full);

		bs.BUSINES_ADDR(bs.BUSINES_ARG); //函数名（函数参数）就去执行这个函数了

		pthread_mutex_lock(&p->thread_lock);
		--p->thread_busy;
		pthread_mutex_unlock(&p->thread_lock);

	}
	pthread_exit(NULL);

}

