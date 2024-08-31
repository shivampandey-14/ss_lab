/*
-------------------------------------------------------
-------------------------------------------------------

Name - 24.c
Author - Shivam Pandey
Description - Write a program to create a orphan process.
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	int f=fork();
	if(f==0)
	{
		printf("child is created with process id as : %d and as parent process with id a:s %d\n",getpid(),getppid());
		sleep(5);
		printf("Child is now orphan process\n");
		printf("Child process (PID: %d) is now an orphan, adopted by init PID: %d", getpid(), getppid());
	}
	else
	{
		printf("parent process is created with id %d\n",getpid());
		exit(0);
	}
	return 0;
}
