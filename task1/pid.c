#include<stdio.h>
#include<unistd.h>
void main()
{
	pid_t pid;
	pid=getpid();
	printf("%d\n",pid);
	while(1);
}
