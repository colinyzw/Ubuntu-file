#include <spider.h>


int spider_rd(container_t* wct,container_t* yct,const char* url)
{
    int flag;
    flag = wct->rear;

    while(flag % wct->max != wct->front)
    {
        if((strncmp(wct->url_list[flag].origin_url,url,strlen(url)))==0)
            return 0;
        flag++;
    }

    flag = yct->rear;
    while(flag % yct->max != yct->front)
    {
        if((strncmp(yct->url_list[flag].origin_url,url,strlen(url)))==0)
            return 0;
        flag++;
    }

    return 1;

}
