#include<stdio.h>
#include<pthread.h>
void *evenfun(void * );
void *oddfun(void * );
void main()
{
	pthread_t ti1,ti2;
	void *ptr;
	int n;
	printf("Enter the range of numbers:\n");
	scanf("%d",&n);
	pthread_create(&ti1,NULL,evenfun,&n);
	pthread_create(&ti2,NULL,oddfun,&n);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *evenfun(void *ptr)
{
	int i,n;
	n=*(int*)ptr;
	for(i=0;i<n;i++)
	{
		if(i%2==0)
			printf("Even no :%d\n",i);
	}
	return 0;
}
void *oddfun(void *ptr)
{
	int i,n;
	n=*(int*)ptr;
	for(i=0;i<n;i++)
	{
		if(i%2!=0)
			printf("Odd no :%d\n",i);	
	}
	return 0;
}
