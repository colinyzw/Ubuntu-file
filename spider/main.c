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
    //const char* tmp = "http://i0.hdslb.com/bfs/article/a72698c1e01357df6b9767be1f1c85f809add0f3.jpg";
    const char* tmp = "https://baike.baidu.com/item/%E7%BB%9D%E5%9C%B0%E6%B1%82%E7%94%9F/20321989?fromtitle=PUBG&fromid=22222335&fr=aladdin";
    spider_controller(tmp);

    return 0;
}
