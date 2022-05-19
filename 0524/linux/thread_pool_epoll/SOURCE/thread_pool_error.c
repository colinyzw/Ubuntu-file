//错误处理
#include<THREAD_POOL.h>

void thread_pool_error(const char* strerr,int exitcode,int errcode)
{
	if(errcode == FALSE)
	{
		perror(strerr);
		exit(exitcode);

	}
	else
	{
		printf("%s:%s\n",strerr,strerror(errcode));
		exit(exitcode);
	}
}
