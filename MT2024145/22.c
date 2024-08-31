/*
-------------------------------------------------------
-------------------------------------------------------

Name - 22.c
Author - Shivam Pandey
Description - Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes.
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
int main()
{
	int fd=open("requirement_22.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);
	int f=fork();
	char str[]="i am child\n";
	char str1[]="i am parent\n";
	if(f==0)
	{
		printf("writtrn by child\n");
		write(fd,str,strlen(str));
	}
	else
	{
		printf("writtrn by parent\n");
                write(fd,str1,strlen(str1));
	}
	close(fd);
	return 0;
}
