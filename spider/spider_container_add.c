#include <spider.h>


int spider_container_add(container_t* ct,url_t node)
{
    if(ct->max == ct->cur)
        return -1;

    ct->url_list[ct->front] = node;
    ct->front = (ct->front+1)%ct->max;
    ++ct->cur;
    return 0;
}
