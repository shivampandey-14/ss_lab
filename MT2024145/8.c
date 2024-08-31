/*
-------------------------------------------------------
-------------------------------------------------------

Name-8.c
Author-shivam Pandey
Description-Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date-17-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
	char buffer[1024];
	char reads[1024];
	ssize_t count;
	int index=0;
	int fd=open("ss-7-test.txt",O_RDONLY);
	if(fd==-1)
       	{
        	perror("Error opening file");
        	return 1;
    	}
	while((count=read(fd,buffer,sizeof(buffer)))>0)
	{
		for(int i=0;i<count;i++)
		{
			reads[index++]=buffer[i];
			if(buffer[i]=='\n' || index==sizeof(reads)-1)
		       	{
                		reads[index]='\n';
                		write(1,reads,index);
                		index=0;
            		}
		}
	}
	if(count==-1)
	{
		perror("unable to read file");
		close(fd);
		return 1;
	}
	close(fd);
	return 0;
}

