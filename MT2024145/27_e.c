/*
-------------------------------------------------------
-------------------------------------------------------
Name - 27e.c
Author - Shivam Pandey
Description - Write a program to execute ls -Rl by the following system calls
e. execvp
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        char *arg[]={"ls","-Rl",(char *)NULL};
        if(execvp("ls",arg)==-1)
        {
                printf("error while executing command");
                return 1;
        }
        return 0;
}

