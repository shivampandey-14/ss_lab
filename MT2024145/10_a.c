/*
-------------------------------------------------------
-------------------------------------------------------

Name-10.c
Author-Shivam Pandey
Description-Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date-17-08-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd=open("ss-10-a-test.txt",O_RDWR,0666);
	char *c="1234567890";
	ssize_t count=write(fd,c,10);
	if(count<=0)
	{
		perror("no wriitng done");
		close(fd);
		return 1;
	}
	off_t offset=lseek(fd,10,SEEK_CUR);
	if(offset==(off_t)-1) 
	{
        	perror("Failed to lseek");
        	close(fd);
        	return 1;
    	}
	char *c2="abcdefghij";
	count=write(fd,c2,10);
	if(count<=0)
        {
                perror("no wriitng done");
                close(fd);
                return 1;
        }
	printf("%ld",offset);
	close(fd);
	return offset;
}
