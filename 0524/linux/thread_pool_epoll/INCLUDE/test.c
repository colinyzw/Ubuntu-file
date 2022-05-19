/****************************************************“
  > File Name: test.c
  > Author: youzhiwei
  > EMail: 859971493@qq.com
  > Created Time: 2022年05月19日 星期四 13时01分29秒
  > Modified Time:2022年05月19日 星期四 13时01分29秒
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
    int* array;
    array = (int*)malloc(sizeof(int) * 5);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    for(int i = 0;i<5;i++)
        printf("array[%d]:%d\n",i,array[i]);
}
