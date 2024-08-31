/*
============================================================================
Name : 19.c
Author : Shivam Pandey
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 25th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include<sys/resource.h>
unsigned long long rdtsc()
{
	unsigned long long dst;
	asm volatile("rdtsc":"=A" (dst));
}
int main()
{
	int i,nanoSec;
	unsigned long long int start,end;
	start = rdtsc();
	for(i=0;i<=10000;i++)
	{
		getpid();
	}
	end = rdtsc();

	nanoSec = (end-start) / 4.60;
	printf("getpid() takes %d nano seconds\n",nanoSec);
	return 0;
}
