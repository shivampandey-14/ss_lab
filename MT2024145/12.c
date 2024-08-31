/*
-------------------------------------------------------
-------------------------------------------------------

Name-12.c
Author-Shivam Pandey
Description-Write a program to find out the opening mode of a file. Use fcntl.
Date-25-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void print_open_mode(int flags) 
{
    if(flags&O_RDONLY)
    {
        printf("File opened in read-only mode.\n");
    } 
    if(flags&O_WRONLY) 
    {
        printf("File opened in write-only mode.\n");
    }
    if(flags&O_RDWR)
    {
        printf("File opened in read/write mode.\n");
    }
}

int main() {
    char *filename = "sample.txt";
    int fd= open(filename, O_RDWR | O_CREAT ,0777);
    if(fd==-1) 
    {
        perror("open");
        return 1;
    }
    int flags=fcntl(fd, F_GETFL);
    if(flags==-1) 
    {
        perror("fcntl");
        close(fd);
        return 1;
    }
    print_open_mode(flags);
    close(fd);
    return 0;
}

