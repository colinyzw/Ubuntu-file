#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>//dns

typedef struct
{
    char origin_url[4096];
    char domain[1024];
    char save_path[1024];
    char file[1024];
    char ip[16];
    int http_type;//http = 0;https = 1;
    int port;
}url_t;

int spider_net_init();//网络初始化
int spider_analytical_url(url_t*);//对原始url进行解析，提取关键内容
int spider_connect_webserver(int,url_t*);//连接资源所在的web服务

