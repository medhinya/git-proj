#include<stdio.h>
#include<fcntl.h>
void main()
{
	int ret;
	ret=open("pm.txt",O_CREAT|O_RDWR,0664);
	printf("%d\n",ret);
}
