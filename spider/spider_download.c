#include <spider.h>


int spider_download(int webfd,char* request_head,url_t node,ssl_t* ssl)
{
    int code;//类型响应码
    char recv_buffer[8192];
    char response_buffer[4096];
    ssize_t recv_size;//读取大小
    char* pos = NULL;//分界地址\r\n\r\n
    int fd;//存储描述符

    bzero(recv_buffer,sizeof(recv_buffer));
    bzero(response_buffer,sizeof(response_buffer));
    if(ssl==NULL){
        //发送请求
        send(webfd,request_head,strlen(request_head),0);
        printf("<<spider step 5 >>send request_head success..\n");

        //first recv
        recv_size = recv(webfd,recv_buffer,sizeof(recv_buffer),0);

        //查找分界地址
        if((pos = strstr(recv_buffer,"\r\n\r\n"))==NULL){
            printf("spider_download >> strstr call failed\n");
            close(webfd);
            return -1;
        }

        //从recv_buffer中获取响应头数据
        snprintf(response_buffer,pos-recv_buffer+4,"%s",recv_buffer);
        printf("<<spider step 6>>get response head:\n%s",response_buffer);

        //辨别响应码
        code = spider_get_statuscode(response_buffer);

        if(code == 200)
        {
            fd = open(node.file,O_RDWR|O_CREAT,0664);
            //将first recv中的部分响应内哦荣写入文件
            write(fd,pos+4,recv_size-(pos-recv_buffer+4));
            //其余的相应提内容循环读写
            while((recv_size=recv(webfd,recv_buffer,sizeof(recv_buffer),0))>0)
                write(fd,recv_buffer,recv_size);

            //文件下载完毕
            close(fd);
            close(webfd);
            printf("<<spider step 7>>http response code '%d'download success..\n",code);
            return 0;
        }
    }else{
          //发送请求
          SSL_write(ssl->ssl_socket,request_head,strlen(request_head));
          printf("<<spider step 5 >>https send request_head success..\n");

          //first recv
          recv_size = SSL_read(ssl->ssl_socket,recv_buffer,sizeof(recv_buffer));

          //查找分界地址
          if((pos = strstr(recv_buffer,"\r\n\r\n"))==NULL){
              printf("spider_download >> strstr call failed\n");
              close(webfd);
              return -1;
          }

          //从recv_buffer中获取响应头数据
          snprintf(response_buffer,pos-recv_buffer+4,"%s",recv_buffer);
          printf("<<spider step 6>>get response head:\n%s",response_buffer);

          //辨别响应码
          code = spider_get_statuscode(response_buffer);

          if(code == 200)
          {
              fd = open(node.file,O_RDWR|O_CREAT,0664);
              //将first recv中的部分响应内哦荣写入文件
              write(fd,pos+4,recv_size-(pos-recv_buffer+4));
              //其余的相应提内容循环读写
              while((recv_size=SSL_read(ssl->ssl_socket,recv_buffer,sizeof(recv_buffer)))>0)
                  write(fd,recv_buffer,recv_size);

              //文件下载完毕
              close(fd);
              close(webfd);
              printf("<<spider step 7>>response code '%d' https download success..\n",code);
              free(ssl);
              return 0;
          }else{
              close(fd);
              free(ssl);
          }

    }
    printf("<<spider step 7>> response code '%d' download failed..\n",code);
    close(webfd);
    ssl=NULL;
    return -1;
}
