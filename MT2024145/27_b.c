/*
-------------------------------------------------------
-------------------------------------------------------
Name - 27b.c
Author - Shivam Pandey
Description - Write a program to execute ls -Rl by the following system calls
b. execlp
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	if(execlp("ls","ls","-Rl",(char *)NULL)==-1)
		printf("error while executing the program");
	return 0;
}

