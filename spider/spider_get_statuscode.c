#include <spider.h>


int spider_get_statuscode(char* response_head)
{
    //HTTP/1.1 200 OK\r\n  HTTP/1.1 404 OK
    char str_code[10];
    bzero(str_code,10);
    int code;

    regex_t reg;
    regmatch_t match[2];
    regcomp(&reg,"HTTP/1.1 \\([^\r\n]\\+\\?\\)\r\n",0);//正则生成 函数把指定的规则表达式第二个参数编译成一种特定的数据格式reg,可以使匹配更有效
    if((regexec(&reg,response_head,2,match,0))==0)
    {
        snprintf(str_code,match[1].rm_eo - match[1].rm_so + 1,"%s",response_head+match[1].rm_so);
        sscanf(str_code,"%d ",&code);
        regfree(&reg);
        return code;
    }
    regfree(&reg);
    return -1;

}
