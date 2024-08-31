/*
-------------------------------------------------------
-------------------------------------------------------

Name-21.c
Author-Shivam Pandey
Description-Write a program, call fork and print the parent and child process id.
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int x=fork();
	if(x==0)
	{
		printf("this is child process id %d\n",getpid());
	}
	else
		printf("This is parent process id %d\n",getpid());
	return 0;
}
