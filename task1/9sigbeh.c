#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler(int);
void main()
{

	signal(2,myhandler);
	while(1)
	{
		printf("%d\n",getpid());
	}
}
void myhandler(int signo)
{
	printf("Received signal no: %d\n",signo);
	sleep(10);
}




