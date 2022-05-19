#include <spider.h>

int spider_analytical_url(url_t* node)
{
    int flag;
    int i = 0;
    int start;
    int filesize = 0;

    bzero(node->domain,sizeof(node->domain));
    bzero(node->save_path,sizeof(node->save_path));
    bzero(node->file,sizeof(node->file));
    bzero(node->ip,sizeof(node->ip));
    const char* http_array[]={"http://","https://",NULL};

    //分辨http协议类型
    if(strncmp(node->origin_url,http_array[0],strlen(http_array[0]))==0){
        node->http_type = 0;
        node->port = 80;
        start = strlen(http_array[0]);
    }else{
        node->http_type = 1;
        node->port = 443;
        start = strlen(http_array[1]);
    }

    //域名
    for(flag = start;node->origin_url[flag]!='/';flag++){
        node->domain[i] = node->origin_url[flag];
        i++;
    }
    //文件名长度
    for(flag = strlen(node->origin_url);node->origin_url[flag]!='/';flag--,filesize++);

    //文件名
    i=0;
    for(flag = strlen(node->origin_url)-filesize+1;node->origin_url[flag]!='\0';flag++){
        node->file[i] = node->origin_url[flag];
        i++;
    }
    //存储路径
    i = 0;
    for(flag = start + strlen(node->domain);flag<strlen(node->origin_url)-filesize+1;flag++){
        node->save_path[i] = node->origin_url[flag];
        i++;
    }
    //ip获取
    struct hostent* ent = NULL;
    if((ent = gethostbyname(node->domain))!=NULL){
        inet_ntop(AF_INET,ent->h_addr_list[0],node->ip,16);
    }

    printf("<<Spider Step 2>>\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%d and %d\n",node->origin_url,node->domain,node->save_path,node->file,node->ip,node->port,node->http_type);
    return 0;

}
