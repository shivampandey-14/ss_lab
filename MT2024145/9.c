/*
============================================================================
Name : 9.c
Author :Shivam Pandey
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 17th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("give arguments\n");
		return 1;
	}
	char *Name = argv[1];
	struct stat Info;
	if(stat(Name,&Info) == -1)
	{
		perror("stat error\n");
		return 1;
	}
	printf("i-node: %ld\n",(long)Info.st_ino);
	printf("uid: %d\n",Info.st_uid);
	printf("gid: %d\n",Info.st_gid);
	printf("Number of hard links: %ld\n",(long)Info.st_nlink);
	printf("size: %ld\n",(long)Info.st_size);
	printf("block size: %ld\n",(long)Info.st_blksize);
	printf("Number of blocks: %ld\n",(long)Info.st_blocks);
	printf("Last access on: %s\n",ctime(&Info.st_atime));
	printf("Last update on: %s\n",ctime(&Info.st_mtime));
	printf("Last change on: %s\n",ctime(&Info.st_ctime));

	return 0;
}
