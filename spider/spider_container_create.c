#include <spider.h>

container_t* spider_container_create(int size)
{
    container_t* ct = NULL;
    if((ct = (container_t*)malloc(sizeof(container_t)))==NULL)
    {
        perror("container_create >> malloc ct error");
        exit(0);
    }
    if((ct->url_list = (url_t*)malloc(sizeof(url_t)*size))==NULL)
    {
        perror("container_create >> malloc url_list error");
        exit(0);
    }

    ct->front = 0;
    ct->rear = 0;
    ct->cur = 0;
    ct->max = size;
    return ct;
}
