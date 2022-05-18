#include <spider.h>

int spider_create_requesthead(char* request_head,url_t node)
{
	bzero(request_head,4096);
	sprintf(request_head,"GET %s HTTP/1.1\r\n"\
	                     "Accept:text/html,application/xhtml+xml;q=0.9,image/webp;q=0.8\r\n"\
	                     "USER-Agent:Mozilla/5.0 (x11;linux x86_84)\r\n"\
	                     "Host:%s\r\n"\
	                     "Connection:close\r\n\r\n",node.origin_url,node.domain);
	printf("<<spider step 4>>create request head:\n%s",request_head);
	return 0;
}
