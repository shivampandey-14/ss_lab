/*
============================================================================
Name : 7.c
Author : Shivam Pandey
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 17th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	int fd1=open("ss-7-test.txt",O_RDONLY);
	int fd2=creat("ss-7-test2.txt",0777);
	char buffer[1024];
	ssize_t countr,countw;
	while((countr=read(fd1,buffer,sizeof(buffer)))>0)
	{
		countw=write(fd2,buffer,countr);
		if (countr != countw)
	       	{
           		 perror("Error writing to destination file");
           		 close(fd1);
           		 close(fd2);
			 return 1;
        	}
	}
	close(fd1);
	close(fd2);
}
