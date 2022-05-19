//业务添加
#include<THREAD_POOL.h>

int thread_pool_add_busines(thread_pool_t * p,busines_t bs)
{
	if(p->thread_shutdown != TRUE) 
		return -1;
	pthread_mutex_lock(&p->thread_lock);
	while(p->b_cur == p->b_max) //任务队列满了 
	{
		pthread_cond_wait(&p->not_full,&p->thread_lock); //挂起
		if(p->thread_shutdown != TRUE) //这过程中有可能有人关了 
		{
			pthread_mutex_unlock(&p->thread_lock);
			return -1;
		}

	}
	p->business_queue[p->b_front].BUSINES_ADDR = bs.BUSINES_ADDR;
	p->business_queue[p->b_front].BUSINES_ARG = bs.BUSINES_ARG;
	++p->b_cur;

	p->b_front = (p->b_front + 1) % p->b_max; //环形偏移

	pthread_mutex_unlock(&p->thread_lock);
	pthread_cond_signal(&p->not_empty);  //发送一个信号给另外一个正在处于阻塞等待状态的线程,使其脱离阻塞状态,继续执行

	return 0;
}
