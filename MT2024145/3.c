/*
============================================================================
Name : 3.c
Author : Shivam Pandey
Description :3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 17th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char *c="test-3.txt";
	int x=creat(c,0774);
	if(x==-1){
		perror("error");
		return 1;
	}
	close(x);
	return 0;
}
