#include<THREAD_POOL.h>

int if_thread_alive(pthread_t tid)
{
	//测试tid指向的线程是否存活，如果线程有效 返回TRUE 失效返回FALSE
	int thread_err;
	thread_err = pthread_kill(tid,0); //如果信号编为0,表示测试一个线程是否存活

	if(thread_err == ESRCH)
		return FALSE;
	else
		return TRUE;
}
