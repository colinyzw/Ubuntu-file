#include <spider.h>

int spider_net_init(void)
{
    int sockfd;
    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(8080);
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("spider_net_init -> socket error");
        exit(0);
    }

    if((bind(sockfd,(struct sockaddr*)&myaddr,sizeof(myaddr)))==-1)
    {
        perror("spider_net_init -> bind error");
        exit(0);
    }
    printf("<<Spider Step 1>> net init success%d\n",sockfd);


    return sockfd;
}
