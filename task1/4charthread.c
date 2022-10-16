#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
char str[100];
void *thread_fun1(void *ptr);
void *thread_fun2(void *ptr);
void main()
{
	
	pthread_t ti1,ti2;
	void *ptr;
	printf("Enter the string:\n");
        scanf("%[^\n]s",str);
	pthread_create(&ti1,NULL,thread_fun1,&str);
	pthread_create(&ti2,NULL,thread_fun2,&str);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *thread_fun1(void *ptr)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		sleep(1);
		if(str[i]>=65 && str[i]<=90)
			printf("Thread 1 :%c\n",((char *)ptr)[i]);
		
	}
}
void *thread_fun2(void *ptr)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		sleep(1);
		if(str[i]>=97 && str[i]<=122)
			printf("Thread 2 :%c\n",((char *)ptr)[i]);
		
	}
}



