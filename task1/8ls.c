#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	//char *argv[]={"ls",0};
	pid_t pid;
	int ret,x;
	pid=fork();
	if(pid>0)
	{
		printf("%d\n",ret);
	}
	else
	{
		printf("%d\n",getpid());
		execvp("pwd",argv);
	}
}

