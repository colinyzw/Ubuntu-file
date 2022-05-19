#include<SOCKET_API.h>
/* 服务端宏定义 */
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8000
#define BUFSIZE 1500
#define BACKLOG 128
#define TIMEOUT 2 //等待超时
#define IPSIZE 16
#define EPOLLSIZE 90000
#define TRUE 1
#define FALSE 0
#define THREAD_CODE 10 //扩容缩减量

int epfd; //监听树描述符
pthread_mutex_t busines_lock; //业务锁

/* 结构体定义 */
typedef struct{
	void * (*BUSINES_ADDR)(void *); //业务地址 函数指针 哪个业务
	void * BUSINES_ARG; //业务参数 socket
}busines_t; //业务类型
//业务传给线程处理

typedef struct{
	/*线程池阈值*/
	int thread_shutdown; //线程池开关0/1 , 根据开关决定是否结束线程池
	int thread_max; //线程最大值
	int thread_min; //线程最小值
	int thread_busy;//繁忙线程数
	int thread_alive; //有效线程数量
	int thread_exitcode; //用于线程缩减
	pthread_t * customer_tids; //消费者线程tid数组
	pthread_t manager_tid; //保存管理者线程tid

	busines_t * business_queue; //保存业务的唤醒队列
	int b_front; //业务队列头索引
	int b_rear; //业务队列尾索引
	int b_max; //业务队列最大数
	int b_cur; //业务队列当前业务数

	pthread_mutex_t thread_lock; //互斥锁
	pthread_cond_t not_full; //生产者条件变量
	pthread_cond_t not_empty; //消费者条件变量
}thread_pool_t; //线程池类型

/* 服务端模型模块分析 */

void thread_pool_error(const char * strerror , int exitcode , int errno);
//如果errno==0则是标准错误处理，如果errno>0则是线程函数错误处理  将错误处理分成两类

int thread_pool_net_init(void); //成功返回serverfd , 失败返回-1  //服务端网络初始化

int thread_pool_epoll_init(int Sockfd); //成功返回监听树描述符，失败返回-1  //服务端epoll初始化  且监听serverfd

thread_pool_t * thread_pool_create(int Max , int Min , int QueMax); //线程池创建初始化，成功返回线程池地址

int thread_pool_destroy(thread_pool_t *); //释放销毁线程池资源 

int thread_pool_epoll_listen(int epfd , thread_pool_t * p,int sockfd);//负责网络IO事件监听，辨别就绪并添加任务 producer

int thread_pool_add_busines(thread_pool_t * , busines_t); //生产者向线程池中添加业务

void * thread_pool_customer_job(void * arg); //消费者默认工作，创建时传递线程池参数 从任务队列中取任务

void * thread_pool_manager_job(void * arg); //管理者默认工作，创建时传递线程池参数 需要线程池中的阈值

int if_thread_alive(pthread_t); //测试一个线程是否存活 ? 返回0表示线程已经结束，1表示线程存活

void * BUSINES_ACCEPT(void * arg); //TCP连接业务

void * BUSINES_RESPONSE(void * arg); //业务处理

