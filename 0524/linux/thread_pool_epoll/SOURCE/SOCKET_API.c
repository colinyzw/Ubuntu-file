//socket套接字函数包裹实现
#include<SOCKET_API.h>
int SOCKET(int domain ,int type, int protocal)
{
	int reval;
	if((reval = socket(domain,type,protocal)) == -1){
		perror("socket create error");
		exit(-1);
	}
	return reval;
}

int BIND(int sockfd ,const struct sockaddr* addr , socklen_t addrlen)
{
	int reval;
	if((reval = bind(sockfd,addr,addrlen)) == -1){
		perror("bind call failed");
		exit(-1);
	}
	return reval;
}
int LISTEN(int sockfd ,int backlog)
{
	int reval;
	if((reval = listen(sockfd,backlog)) == -1){
		perror("listen call failed");
		exit(-1);
	}
	return reval;
}
int ACCEPT(int sockfd , struct sockaddr* addr , socklen_t* addrlen)
{
	int reval;
	if((reval = accept(sockfd,addr,addrlen)) == -1){
		perror("accept call failed");
		exit(-1);
	}
	return reval;
}

int CONNECT(int sockfd ,const struct sockaddr* addr ,socklen_t addrlen)
{
	int reval;
	if((reval = connect(sockfd,addr,addrlen)) == -1){
		perror("connect call failed");
		exit(-1);
	}
	return reval;
}
ssize_t RECV(int sockfd ,void* buffer ,size_t len ,int flags)
{
	int reval;
	if((reval = recv(sockfd,buffer,len,flags)) == -1){
		if(errno == EAGAIN)
		{
			printf("RECV NONBLOCK RETURN\n");
			return reval;
		}
		perror("recv call failed");
		exit(-1);
	}
	return reval;
}
ssize_t SEND(int sockfd ,const void* buffer ,size_t len ,int flags)
{
	int reval;
	if((reval = send(sockfd,buffer,len,flags)) == -1){
		perror("send call failed");
		exit(-1);
	}
	return reval;
}


