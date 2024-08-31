/*
-------------------------------------------------------
-------------------------------------------------------

Name-16a.c
Author-Shivam Pandey
Description- Write a program to perform mandatory locking.
a. Implement write lock
Date-25-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int fd=open("record.txt",O_CREAT|O_RDWR,0644);
	struct flock savelock,lock;
	lock.l_type=F_WRLCK;
	lock.l_start=0;
	lock.l_whence=SEEK_SET;
	lock.l_len=0;
	savelock=lock;
	fcntl(fd,F_GETLK,&lock);
	if(lock.l_type==F_RDLCK)
	{
		printf("READ LOCK IS ALREADY THERE\n");
			while(lock.l_type==F_RDLCK)
			{
				fcntl(fd,F_GETLK,&lock);
			}
	}
	if(fcntl(fd,F_SETLKW,&savelock)==-1)
	{
		printf("error while locking\n");
	}
	printf("applying the lock\n");
	printf("enter any key to unlock\n");
	getchar();
	savelock.l_type=F_UNLCK;
	if(fcntl(fd,F_SETLK,&savelock)==-1)
	{
		perror("error while unlocking\n");
		close(fd);
		return 1;
	}
	printf("unlocking succesfully completed\n");
	close(fd);
	return 0;
}
	

