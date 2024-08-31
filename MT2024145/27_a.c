/*
-------------------------------------------------------
-------------------------------------------------------
Name - 27a.c
Author - Shivam Pandey
Description - Write a program to execute ls -Rl by the following system calls
a. execl
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	if(execl("/bin/ls","ls","-Rl",(char *) NULL)==-1);
	printf("error while opening the command");
	return 0;
}
