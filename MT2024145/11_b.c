/*
-------------------------------------------------------
-------------------------------------------------------

Name-11b.c
Author-Shivam Pandey
Description-Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
b) use dup2
Date-25-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    int fd=open("testfile-11-a.txt",O_RDWR|O_CREAT,0666);
    if (fd<0) {
        perror("Failed to open file");
        return 1;
    }
    int fd_dup=10;
    if (dup2(fd,fd_dup)<0) {
        perror("Failed to duplicate file descriptor");
        close(fd);
        return 1;
    }
    char *data1="Data from fd\n";
    ssize_t bytes_written=write(fd,data1,strlen(data1));
    if(bytes_written<0)
    {
        perror("Failed to write to file using fd");
        close(fd);
        close(fd_dup);
        return 1;
    }
    char *data2="Data from fd_dup\n";
    bytes_written=write(fd_dup,data2,strlen(data2));
    if(bytes_written<0)
    {
        perror("Failed to write to file using fd_dup");
        close(fd);
        close(fd_dup);
        return 1;
    }
    close(fd);
    close(fd_dup);

    return 0;
}
