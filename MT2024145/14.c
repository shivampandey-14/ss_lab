/*
============================================================================
Name : 14.c
Author : Shivam Pandey
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 25th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <sys/select.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		perror("enter correct number of arguments");
		return 1;
	}
	struct stat Info;
	char *Name = argv[1];
	if((stat(Name,&Info)) == -1)
	{
		perror("file does not exist");
		return 1;
	}
	char buffer[1024];
	snprintf(buffer,sizeof(buffer),"file %s",Name);
	int res=system(buffer);
	if(res==-1)
	{
		perror("error occured");
		return 1;
	}
	return 0;
}
