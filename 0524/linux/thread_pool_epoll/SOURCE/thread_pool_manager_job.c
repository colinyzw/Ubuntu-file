#include<THREAD_POOL.h>

void *thread_pool_manager_job(void *arg)
{
	thread_pool_t *p = NULL;
	pthread_detach(pthread_self());
	p = (thread_pool_t *)arg;

	int alive;
	int busy;
	int cur;

	int add;
	int flags;
	int thread_err;

	printf("MANAGER THREAD [0x%x] STARTING ......\n",(unsigned int)pthread_self());

	while(p->thread_shutdown)
	{
		pthread_mutex_lock(&p->thread_lock); //每轮重新获取阀值
		alive = p->thread_alive;
		busy = p->thread_busy;
		cur = p->b_cur;
		pthread_mutex_unlock(&p->thread_lock);

		printf("[THREAD POOL INFO] ALIVE [%d] BUSY [%d] IDEL [%d] B/A [%.2f]\n",alive,busy,alive-busy,(double)busy/alive*100);

		if((cur >= alive - busy || (double)busy/alive *100 >= 70) && alive + THREAD_CODE <= p->thread_max)
		{
			//扩容
			for(add = 0,flags = 0; flags < p->thread_max && add < THREAD_CODE; flags++)

				if( p->customer_tids[flags] == 0 || !if_thread_alive(p->customer_tids[flags]))  // 遍历判断使用tids  （0或者线程死亡）
				{    
					if((thread_err = pthread_create(&p->customer_tids[flags],NULL,thread_pool_customer_job,(void*)p))>0)
						thread_pool_error("thread_pool_manager Dilatation Error",-2,thread_err);

					printf("MANAGER THREAD [0x%x] DILATATION SUCCESS ,CUSTOMER TID [0x%x] ...\n ",(unsigned int)pthread_self(),(unsigned int)p->customer_tids[flags] );

					++add;
					pthread_mutex_lock(&p->thread_lock);
					++p->thread_alive;
					pthread_mutex_unlock(&p->thread_lock);
				}


		}
		if(busy *2 <= alive - busy && alive - THREAD_CODE >= p->thread_min)
		{
			//缩减 管理者和消费者配合缩减 减少管理者任务 让扫描更及时
			pthread_mutex_lock(&p->thread_lock);
			p->thread_exitcode = THREAD_CODE;
			pthread_mutex_unlock(&p->thread_lock);
			for(int i = 0;i<THREAD_CODE;i++)
				pthread_cond_signal(&p->not_empty);   //挂起在not_empty上的线程一定是闲线程 （因为任务队列里没有任务了，就挂起了） 唤醒它 然后到上面杀死
			printf("MANAGER THREAD REDUCE SUCCESS ...\n");

		}
		sleep(TIMEOUT);
	}
	pthread_exit(NULL);
}

