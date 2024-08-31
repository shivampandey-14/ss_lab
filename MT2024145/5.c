/*
============================================================================
Name : 5.c
Author : Shivam Pandey
Description : 5. Write a program to create five new files with infinite loop. Execute the program in the background
		and check the file descriptor table at /proc/pid/fd.
Date: 17th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	for(int i=0;i<5;i++)
	{
		char file[20];
		sprintf(file,"test5_%d",i);
		int fd = creat(file, 0666);
    		if (fd == -1)
	       	{
        		if (errno == EEXIST) 
			{
           			 perror("File exists, and O_EXCL prevented opening the file.\n");
        		}
			else 
			{
            			perror("Error opening file with O_EXCL");
       		 	}
	       		return;
		}
		printf("%d",fd);
	}

	while(1);
	
}
