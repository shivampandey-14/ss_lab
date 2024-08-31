/*
-------------------------------------------------------
-------------------------------------------------------

Name - 23.c
Author - Shivam Pandey
Description - Write a program to create a Zombie state of the running program.
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int fd=fork();
	if(fd)
	{
		printf("parent process\n");
		printf("process id of parent%d\n",getpid());
		printf("putting parent in sleep for 100 sec\n");
		sleep(10);
		printf("parent process is awaking\n");
		int satus;
		wait(&satus);
	}
	else
	{
		printf("child preocess\n");
		printf("process id of chile%d\n",getpid());
		printf("exiting child");
		exit(0);
	}
	return 0;
}

