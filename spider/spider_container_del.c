#include <spider.h>


int spider_container_del(container_t* ct,url_t* node)
{
    if(ct->cur == 0)
        return -1;

    *node = ct->url_list[ct->rear];
    ct->rear = (ct->rear+1)%ct->max;
    --ct->cur;
    return 0;
}
