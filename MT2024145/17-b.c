/*
-------------------------------------------------------
-------------------------------------------------------

Name-17b.c
Author-Shivam Pandey
Description- Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. 
Date-25-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	int ticket=0;
	int fd=open("ticket_count.txt",O_RDWR|O_CREAT,0777);
	if(fd==-1)
	{
		perror("file didnot opened");
		close(fd);
		return 1;
	}
	if((write(fd,&ticket,sizeof(ticket)))==-1)
	{
		perror("error while writing");
		return 1;
	}
	close(fd);
	return 0;
}
