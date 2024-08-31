/*
-------------------------------------------------------
-------------------------------------------------------
Name - 28.c
Author - Shivam Pandey
Description -  Write a program to get maximum and minimum real time priority.
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sched.h>
int main()
{
	int max_priority,min_priority;
	max_priority=sched_get_priority_max(SCHED_FIFO);
	min_priority=sched_get_priority_min(SCHED_FIFO);
	if(max_priority==-1)
	{
		perror("error occured while getting max priority process");
		return 1;
	}
	if(min_priority==-1)
        {
                perror("error occured while getting min priority process");
                return 1;
        }
	printf("maximum priority process is %d\n",max_priority); 
	printf("minimum priority process is %d\n",min_priority);
	return 0;
}
