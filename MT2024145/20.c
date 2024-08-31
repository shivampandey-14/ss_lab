/*
-------------------------------------------------------
-------------------------------------------------------

Name-20.c
Author-Shivam PAndey
Description-Find out the priority of your running program. Modify the priority with nice command
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	int priority;

	priority=nice(5);
	printf("current priority=%d",priority);
	int newpriority;
	newpriority=nice(6);
	printf("new priority=%d",newpriority);
	return 0;
}


