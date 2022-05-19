#include<THREAD_POOL.h>

void *BUSINES_RESPONSE(void *arg)
{
	int clientfd;
	clientfd = *(int*)arg;
	char buffer[BUFSIZE];
	bzero(buffer,BUFSIZE);
	int recvsize ,sendsize;
	int flags;

	while((recvsize = RECV(clientfd,buffer,sizeof(buffer),0))>0){
		flags = 0;
		while(recvsize > flags){
			buffer[flags] = toupper(buffer[flags]);
			flags++;
		}
		sendsize = SEND(clientfd,buffer,recvsize,0);
		printf("CUSTOMER EXEC BUSINES_RESPONSE RECV REQUET [%d] SEND RESPONSE [%d]\n",recvsize,sendsize);
	}
       if(recvsize == 0){
		printf("CUSTOMER EXEC BUSINES_RESPONSE CLIENT EXIST ...\n");
		epoll_ctl(epfd,EPOLL_CTL_DEL,clientfd,NULL);
		close(clientfd);

	}
	return NULL;
}
