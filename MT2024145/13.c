/*
-------------------------------------------------------
-------------------------------------------------------

Name-13.c
Author-Shivam Pandey
Description-Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date-25-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>

int main() 
{
    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");
    int ans;
    ans=select(STDIN_FILENO+1,&readfds,NULL,NULL,&timeout);
    if(ans==-1)
    {
        perror("select()");
       	return 1;
    }
    else if(ans) 
    {
        printf("Data is available to read on stdin.\n");
    }
    else 
    {
        printf("No data available within 10 seconds.\n");
    }
    return 0;
}

