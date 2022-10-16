#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
void main()
{
	int ret,ret1,opt;
	char dir[10];
	while(1)
	{
		printf("Enter the option:0.exit\t 1.make directory\t 2.remove directory\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				exit(0);
			case 1:
		
				printf("Enter the directory name:\n");
				scanf("%s",dir);
				ret=mkdir(dir,0664);
				printf("%d\n",ret);
				break;
			case 2:
				printf("Enter the directory to be removed:\n");
				scanf("%s",dir);
				ret1=rmdir(dir);
				printf("%d\n",ret1);
				break;
		}
	}
	
}

