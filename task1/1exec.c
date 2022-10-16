#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int mp(char **);
int main(int argc,char *argv[])
//int main()
{
	int i,j;
	char m[20];
//	char *argv[20];
	printf("Enter the command:\n");
	scanf("%[^\n]s",m);
	__fpurge(stdin);
//	argv[0]=m;
	for(i=0,j=1;m[i]!='\0';i++)
	{
		if(m[i]==' ')
		{
			m[i]='\0';
			//argv[j]=&m[i+1];
			i++;
			j++;
		}

	}
	//argv[j]=0;
	mp(argv);
	return 0;
}
int mp(char **argv)
{
	int ret,x,i;
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		ret=wait(&x);
		printf("Child process:%d\n",getpid());
		return 0;
	}
	else
	{
		printf("parent process:%d\n",getpid());
		execvp(argv[0],argv);
	}
}
