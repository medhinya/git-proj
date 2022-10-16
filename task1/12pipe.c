#include<stdio.h>
#include<string.h>
#include<unistd.h>
void main()
{
	int fd[2],ret;
	pid_t pid;
	char buf[10];
	ret=pipe(fd);
	pid=fork();
	if(pid>0)
	{
		close(fd[0]);
		ret=write(fd[1],"Hello",strlen("Hello"));
		printf("%d\n",ret);
	}
	else
	{
		close(fd[1]);
		ret=read(fd[0],buf,9);
		buf[ret]='\0';
		printf("%s\n",buf);
	}
}
