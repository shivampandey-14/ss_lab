/*
-------------------------------------------------------
-------------------------------------------------------

Name-18b.c
Author-Shivam Pandey
Description- Write a program to perform Record locking.
b. Implement read lock
Date-25-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
int main()
{
	int fd=open("requirment_18_b.txt",O_RDWR| O_CREAT ,0777);
	if(fd==-1)
	{
		perror("error while opening the file");
		close(fd);
		return 0;
	}
	struct {
		int enrolment;
		char name[20];
		int dept;
	} db;
	int input;
	scanf("%d",&input);
	struct flock savelock ,lock;
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(input-1)*sizeof(db);
	lock.l_len=sizeof(db);
	lock.l_pid=getpid();
	savelock=lock;
	if(fcntl(fd,F_GETLK,&lock)==-1)
	{
		perror("error while locking");
		close(fd);
		return 1;
	}
	else if(lock.l_type==F_WRLCK)
	{
		printf("read lock waiting\n");
		while(lock.l_type==F_WRLCK)
			fcntl(fd,F_GETLK,&lock);
	}
	fcntl(fd,F_SETLKW,&savelock);
	lseek(fd,(input-1)*sizeof(db),SEEK_SET);
	printf("Enter the data at this point:\n");
   	 scanf("%d", &db.enrolment);
   	 scanf("%s", db.name);
   	 scanf("%d", &db.dept);
   	 write(fd, &db, sizeof(db));
	 savelock.l_type = F_UNLCK;
    	if (fcntl(fd, F_SETLK, &savelock) == -1) 
    	{
       		perror("Error unlocking");
		close(fd);
		exit(1);
   	 }
    	close(fd);
	printf("Record written successfully\n");

	    return 0;
}
