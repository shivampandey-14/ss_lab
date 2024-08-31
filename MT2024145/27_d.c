/*
-------------------------------------------------------
-------------------------------------------------------
Name - 27d.c
Author - Shivam Pandey
Description - Write a program to execute ls -Rl by the following system calls
d. execv
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char *arg[]={"ls","-Rl",(char *)NULL};
	if(execv("/bin/ls",arg)==-1)
	{
		printf("error while executing command");
		return 1;
	}
	return 0;
}
