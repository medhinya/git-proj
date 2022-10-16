#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
void mkill(int,int);
int main(int argc,char *argv[])
{
	int signo,pid;
	pid=atoi(argv[1]);
	signo=atoi(argv[2]);
	if(argc==3)
	{
		mkill(pid,signo);
	}
	else
	printf("end\n");
}
void mkill(int pid,int signo)
{
	printf("Own kill function\n");
	int p=kill(pid,signo);
	printf("success %d\n",p);
	printf("end.....\n");
}

