//socket套接字函数包裹定义
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ctype.h>

#include<signal.h>
#include<sys/wait.h>
#include<pthread.h>

#include<sys/select.h>
#include<poll.h>
#include<sys/epoll.h>
#include<errno.h>
#include<sys/stat.h>
#include<fcntl.h>


int SOCKET(int ,int ,int );
int BIND(int ,const struct sockaddr* , socklen_t);
int LISTEN(int ,int );
int ACCEPT(int ,struct sockaddr* ,socklen_t* );
int CONNECT(int ,const struct sockaddr* , socklen_t );
ssize_t RECV(int ,void* ,size_t ,int );
ssize_t SEND(int ,const void* ,size_t ,int );
