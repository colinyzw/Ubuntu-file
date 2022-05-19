#include <spider.h>

ssl_t* spider_create_openssl(int webfd)
{
    ssl_t* ssl = (ssl_t*)malloc(sizeof(ssl_t));

    SSL_load_error_strings();//初始化SSL错误处理
    SSL_library_init();//初始化SSL库
    OpenSSL_add_ssl_algorithms();//加载加密函数和散列函数

    ssl->ssl_ctx = SSL_CTX_new(SSLv23_method());//生成SSL版本信息上下文

    ssl->ssl_socket = SSL_new(ssl->ssl_ctx);

    SSL_set_fd(ssl->ssl_socket,webfd);

    SSL_connect(ssl->ssl_socket);//与服务端完成安全认证

    printf("<<spider step ?>>SSL connect web success..\n");

    return ssl;

    //SSL_read(读取并解密);     SSL_write(加密并发送);

}
