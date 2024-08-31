/*
============================================================================
Name : 6.c
Author : Shivam Pandey
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 17th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main()
{
	char buffer[1024];
	ssize_t count;
	while((count=read(STDIN_FILENO,buffer,sizeof(buffer)))>0)
	{
		write(STDOUT_FILENO,buffer,count);
	}
	if(count==-1)
	{
		perror("error");
		return 1;
	}
	return 1;
}
