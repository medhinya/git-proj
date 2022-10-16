#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void *even_fun(void *);
void *odd_fun(void *);
void main()
{
	pthread_t ti1,ti2;
	void *ptr;
	int n;
	printf("Enter the range of numbers:\n");
	scanf("%d",&n);
	pthread_create(&ti1,NULL,even_fun,&n);
	pthread_create(&ti2,NULL,odd_fun,&n);
	pthread_mutex_lock(&mutex);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *even_fun(void *ptr)
{
	int i,n;
	n=*(int*)ptr;
	for(i=0;i<n;i++)
	{
		pthread_mutex_lock(&mutex);
		if(i%2==0)
		{
			printf("Even using cond:%d\n",i);
		}
			pthread_cond_wait(&cond,&mutex);
			pthread_mutex_unlock(&mutex);	
	}
			
	return 0;
}
void *odd_fun(void *ptr)
{
        int i,n;
        n=*(int*)ptr;
        for(i=0;i<n;i++)
        {
                pthread_mutex_lock(&mutex);
                if(i%2!=0)
                {
                        printf("Odd using cond:%d\n",i);
		}
			pthread_mutex_unlock(&mutex);
			pthread_cond_signal(&cond);
	}
        return 0;
}


			
