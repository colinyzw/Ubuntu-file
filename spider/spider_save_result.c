#include <spider.h>

int spider_save_result(const char* title,const char* desc,const char* link)
{
    char result[20000];
    bzero(result,sizeof(result));
    const char* start ="<html>\r\n<head>\r\n<meta http-equiv=\"Content-Type\"content=\"text/html;charset=utf-8\">\r\n</head>\r\n<table border=\"1\" cellspacing=\"0\" cellpadding=\"0\" width=\"1900\">\r\n<caption>百科词条数据集</caption>\r\n<tr><th>词条标题</th><th>词条描述</th><th>词条链接</th></tr>\r\n";
    const char* end="</table>\r\n</html>\r\n";

    if(result_number == 0){
        write(rfd,start,strlen(start));
        return 0;
    }
    sprintf(result,"<tr id=%d><td name=\"h1\">%s</td><td name=\"description\">%s</td><td name=\"link\">%s</td></tr>\r\n",result_number,title,desc,link);
    write(rfd,result,strlen(result));
    bzero(result,sizeof(result));
    if(Result_max== result_number)
    {
        write(rfd,end,strlen(end));
        close(rfd);
    }
    return 0;
}
