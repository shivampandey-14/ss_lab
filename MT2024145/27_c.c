/*
-------------------------------------------------------
-------------------------------------------------------
Name - 27c.c
Author - Shivam Pandey
Description - Write a program to execute ls -Rl by the following system calls
c. execle
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *envp[]={"shivam-27.c",NULL};
	if(execle("/bin/ls","ls","-Rl",(char *)NULL,envp)==-1)
		printf("error while executing the execle command");
	return 0;
}
