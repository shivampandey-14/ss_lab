/*
-------------------------------------------------------
-------------------------------------------------------
Name-17a.c
Author-Shivam Pandey
Description- Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file
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
	struct flock lock,savelock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	//lock.l_pid=getpid();
	savelock=lock;
	int fd=open("ticket_count.txt",O_RDWR|O_CREAT,0777);
	if(fcntl(fd,F_SETLKW,&lock)==-1)
	{
		perror("error while opening");
		return 1;
	}
	int ticket;
	if(read(fd,&ticket,sizeof(ticket))==-1)
	{
		perror("error while reading ticket number");
		return 1;
	}
	lseek(fd,0,SEEK_SET);
	ticket++;
	if(write(fd,&ticket,sizeof(ticket))==-1)
	{
		perror("error while writting");
		return 1;
	}
	printf("new ticket no.%d",ticket);
	lock.l_type=F_UNLCK;
	if(fcntl(fd,F_SETLKW,&lock)==-1)
        {
                perror("error while opening");
		close(fd);
                return 1;
        }
	close(fd);
	return 0;
}
