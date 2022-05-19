//线程池初始化 创建线程池
#include<THREAD_POOL.h>

thread_pool_t* thread_pool_create(int tmax,int tmin,int bmax) //线程最大数 线程最小数 业务队列最大数
{
	thread_pool_t* p = NULL;
	if((p = (thread_pool_t*)malloc(sizeof(thread_pool_t))) == NULL)
		thread_pool_error("thread_pool_create malloc poll_ptr error",-1,FALSE);

	p->thread_shutdown = TRUE;
	p->thread_max = tmax;
	p->thread_min = tmin;  
	p->thread_busy = 0;
	p->thread_alive = 0;
	p->thread_exitcode = 0;

	//申请消费者线程数组
	if((p->customer_tids = (pthread_t *)malloc(sizeof(pthread_t)*tmax)) == NULL)
		thread_pool_error("thread_pool_create malloc customer_tids error",-1,FALSE);
		bzero(p->customer_tids,sizeof(pthread_t)*tmax);

    //申请任务队列
	if((p->business_queue = (busines_t *)malloc(sizeof(busines_t)*bmax)) == NULL)
		thread_pool_error("thread_pool_create malloc business_queue error",-1,FALSE);

	p->b_front = 0;
	p->b_rear = 0;
	p->b_cur = 0;
	p->b_max = bmax;

	if(pthread_mutex_init(&p->thread_lock,NULL) != 0 || pthread_cond_init(&p->not_full,NULL) != 0 || pthread_cond_init(&p->not_empty,NULL) != 0)
	{
		printf("thread_pool_create init lock or cond error..\n");
		exit(-1);
	}
	
	int thread_err; //错误处理
	for(int flag = 0;flag < tmin;flag++)//预创建消费者线程
	{
		if((thread_err = pthread_create(&p->customer_tids[flag],NULL,thread_pool_customer_job,(void*)p)) > 0)
			thread_pool_error("thread_pool_create customer thread error",-2,thread_err);

		++p->thread_alive;
	}
	//创建出来的线程ID存到哪里去 线程属性传空 线程去完成这个函数 完成这个函数需要的参数 需要线程池参数 要从线程池的任务队列里取出任务

	//创建管理者线程
	if((thread_err = pthread_create(&p->manager_tid,NULL,thread_pool_manager_job,(void*)p)) > 0)
		thread_pool_error("thread_pool_create manager thread error",-2,thread_err);
	printf("[3] thread pool server init Thread Pool successly .. \n");

	return p;
}

