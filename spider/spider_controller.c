#include <spider.h>


int spider_controller(const char* alpha_url)
{
    ssl_t* ssl = NULL;
    int webfd;
    char req_head[0x1000];
    url_t node;
    url_t tmpnode;//传出的url
    container_t* wct = NULL;
    container_t* yct = NULL;
    rfd = open("save_result.html",O_RDWR|O_CREAT,0664);
    //第一次向save_result写入html头部信息
    spider_save_result(NULL,NULL,NULL);

    //容器创建
    wct = spider_container_create(5000);
    yct = spider_container_create(Result_max);

    strcpy(node.origin_url,alpha_url);
    //种子去重校验
    if((spider_rd(wct,yct,node.origin_url)))
        spider_container_add(wct,node);

    while(wct->cur > 0 && result_number < Result_max)//抓取条件
    {
        if(wct->cur >= 100){
            analytical_shutdown =0;
            printf(">>>>>>>>container_cur [%d] analytical up!.\n",wct->cur);
        }else if(wct->cur <= 20){
            analytical_shutdown = 1;
            printf(">>>>>>>>>>conatainer _cur [%d] analytical down!.\n",wct->cur);
        }

        spider_container_del(wct,&tmpnode);//取出一个待处理的url
        webfd = spider_net_init();
        spider_analytical_url(&tmpnode);
        spider_connect_webserver(webfd,&tmpnode);
        spider_create_requesthead(req_head,tmpnode);
        if(tmpnode.http_type)
            ssl = spider_create_openssl(webfd);
        if((spider_download(webfd,req_head,tmpnode,ssl))==-1)
            continue;//跳过本次

        spider_container_add(yct,tmpnode);//处理完毕的url添加到已处理容器

        spider_analytical_html(tmpnode,wct,yct);
    }
    printf("抓取完毕 数据量%d\n",result_number);
    return 0;
}
