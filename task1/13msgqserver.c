#include<stdio.h>
#include<sys/msg.h>
#define MSG_TYPE 1
#define KEY 01111111
void main()
{
	char buf[20],wbuf[20];
	int msqid,ret;
	msqid=msgget(KEY,IPC_CREAT|0640);
	ret=msgrcv(msqid,buf,20,MSG_TYPE,0);
	printf("%d\n",((int*)buf[0]);
	printf("%s",&buf[10]);
	((int *)wbuf)[0]=((int *)buf)[0];
	strcpy(&wbuf[10],"pragna");
	msgsnd(msqid,wbuf,4+strlen(&buf[4])+1,NULL);
	msgctl(msqid,IPC_RMID,0);
}	


	
