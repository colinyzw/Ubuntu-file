#include <spider.h>

int spider_analytical_html(url_t node,container_t* wct,container_t* yct)
{
    int fd;
    int filesize;
    char* html_date = NULL;
    char* jhtml_date = NULL;

    url_t tmpnode;

    //将网页源码数据映射到进程中
    fd = open(node.file,O_RDONLY);
    filesize = lseek(fd,0,SEEK_END);

    if((html_date = mmap(NULL,filesize,PROT_READ,MAP_PRIVATE,fd,0))==MAP_FAILED)
    {
        perror("analytical html >> mmap html call failed");
        exit(0);
    }
    jhtml_date = html_date;
    close(fd);

    //词条中兴趣数据的格式 ？
    //<h1 >标题</h1>:2
    //<meta name="description" content="描述信息">：2
    //词条中URL的格式 ？
    //<a href="/item/词条地址">链接标题</a>:2

    regex_t hreg,dreg,lreg;

    regmatch_t hmatch[2];
    regmatch_t dmatch[2];
    regmatch_t lmatch[2];

    //使用字符串着呢规则表达式生成正则类型
    regcomp(&hreg,"<h1[^>]\\+\\?>\\([^<]\\+\\?\\)</h1>",0);
    regcomp(&dreg,"<meta name=\"description\" content=\"\\([^\"]\\+\\?\\)\">",0);
    regcomp(&lreg,"<a[^>]\\+\\?href=\"\\(/item/[^\"]\\+\\?\\)\"[^>]\\+\\?>[^<]\\+\\?</a",0);

    char h1[1024];
    char desc[8192];
    char link[8192];
    bzero(h1,sizeof(h1));
    bzero(desc,sizeof(desc));
    bzero(link,sizeof(link));

    //匹配并提取数据
    if((regexec(&hreg,html_date,2,hmatch,0))==0)
        snprintf(h1,hmatch[1].rm_eo - hmatch[1].rm_so + 1,"%s",html_date + hmatch[1].rm_so);
    if((regexec(&dreg,html_date,2,dmatch,0))==0)
        snprintf(desc,dmatch[1].rm_eo - dmatch[1].rm_so + 1,"%s",html_date + dmatch[1].rm_so);

    ++result_number;//将结果数量+1
    //将解析出的关键数据写入到html表格中
    spider_save_result(h1,desc,node.origin_url);

    if(analytical_shutdown)//根据解析开关决定是否解析更多词条链接
    {
        while((regexec(&lreg,html_date,2,lmatch,0))==0)
        {
            //    /item/xxxxx
            snprintf(link,lmatch[1].rm_eo - lmatch[1].rm_so + 24,"https://baike.baidu.com%s",html_date+lmatch[1].rm_so);

            //新词条链接去重校验添加到容器
            if(spider_rd(wct,yct,link))
            {
                strcpy(tmpnode.origin_url,link);
                spider_container_add(wct,tmpnode);
            }
            bzero(link,sizeof(link));
            html_date += lmatch[0].rm_eo;
            if(wct->cur + 1 == wct->max)
            {
                printf("未处理容器满！\n");
                break;
            }
        }
    }
    unlink(node.file);//删除源码文件
    regfree(&hreg);
    regfree(&dreg);
    regfree(&lreg);
    munmap(jhtml_date,filesize);
    return 0;
}
