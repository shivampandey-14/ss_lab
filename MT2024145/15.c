/*
-------------------------------------------------------
-------------------------------------------------------

Name-15.c
Author-shivam pandey
Description- Write a program to display the environmental variable of the user (use environ).
Date-25-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
extern char **environ;
int main()
{
	for(char **c=environ;c!=NULL;c++)
	{
		printf("%s\n",*c);
	}
}
