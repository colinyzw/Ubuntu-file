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
#include <regex.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <sys/mman.h>

#define Result_max 10 //爬取数据量

int analytical_shutdown;//0关闭 1开启
int result_number;//结果数量
int rfd;//存储文件描述符


typedef struct
{
    SSL* ssl_socket;
    SSL_CTX* ssl_ctx;
}ssl_t;


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

typedef struct
{
    url_t* url_list;
    int front;
    int rear;
    int cur;
    int max;
}container_t;//url容器类型

int spider_net_init();//网络初始化
int spider_analytical_url(url_t*);//对原始url进行解析，提取关键内容
int spider_connect_webserver(int,url_t*);//连接资源所在的web服务
int spider_create_requesthead(char*,url_t);
int spider_download(int,char*,url_t,ssl_t*);
int spider_get_statuscode(char*);//从响应
ssl_t* spider_create_openssl(int);//通过ssl技术与web服务进行安全认证过程

int spider_controller(const char* alpha_url);
container_t* spider_container_create(int);//url容器创建
int spider_container_add(container_t*,url_t);//向容器添加node
int spider_container_del(container_t*,url_t*);//从容其中获取node

int spider_rd(container_t*,container_t*,const char*);//去重校验，返回1表示无重复，返回0表示重复
int spider_analytical_html(url_t,container_t*,container_t*);//解析更多url，解析关键数据
int spider_save_result(const char*,const char*,const char*);//将关键数据保存到html表格中

