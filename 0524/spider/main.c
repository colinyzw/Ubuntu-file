/****************************************************“
  > File Name: main.c
  > Author: youzhiwei
  > EMail: 859971493@qq.com
  > Created Time: 2022年05月10日 星期二 21时46分08秒
  > Modified Time:2022年05月10日 星期二 21时46分08秒
 ****************************************************/

#include <spider.h>

int main(void)
{
    int sockfd;
    sockfd = spider_net_init();
    const char* tmp = "http://img.zcool.cn/community/0136915ffc655311013fdcc7943e2f.png";
    url_t node;
    strcpy(node.origin_url,tmp);
    spider_analytical_url(&node);
    return 0;
}
