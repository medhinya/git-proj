#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int glob=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void *pthread_fun1(void *);
void *pthread_fun2(void *);
void  main()
{
	pthread_t ti1,ti2;
	int loop;
	printf("Enter the num of iterations:\n");
	scanf("%d",&loop);
	void *ptr;
	pthread_create(&ti1,NULL,pthread_fun1,&loop);
	pthread_create(&ti2,NULL,pthread_fun2,&loop);
	pthread_mutex_lock(&mutex1);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
	printf("main glob:%d\n",glob);
}
void *pthread_fun1(void *ptr)
{
	int i,loop,loc=0;
	loop=*(int*)ptr;
	for(i=0;i<loop;i++)
	{
		pthread_mutex_lock(&mutex);
		loc=glob;
//		printf("loc fun 1:%d\n",loc);
		loc++;
		glob=loc;
		printf("glob fun1:%d\n",glob);
		pthread_mutex_unlock(&mutex1);
	}
	return 0;
}
void *pthread_fun2(void *ptr)
{
	int i,loop,loc=0;
	loop=*(int*)ptr;
	for(i=0;i<loop;i++)
	{
		pthread_mutex_lock(&mutex1);
		loc=glob;
//		printf("loc fun2:%d\n",loc);
		loc++;
		glob=loc;
		printf("glob fun2:%d\n",glob);
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}


