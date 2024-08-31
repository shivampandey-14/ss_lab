/*
-------------------------------------------------------
-------------------------------------------------------
Name - 25.c
Author - Shivam PAndey
Description - Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
void main()
{
    int childA, childB, childC, terminatedChild;
    int waitStatus;

    if ((childA=fork())==0)
    {
        printf("Child A created...\n");
    }
    else
    {
        if((childB=fork())==0)
        {
            printf("Child B created...\n");
        }
        else
        {
            if((childC=fork())==0)
            {
                printf("Child C created...\n");
                printf("Putting child C to sleep for 15 sec\n");
                sleep(15);
                printf("Child C is now awake!\n");
            }
            else
            {
                terminatedChild=waitpid(childC,NULL, 0);
                if (terminatedChild==childC)
                {
                    if (waitStatus==0)
                        printf("Child C has terminated with exit status = 0\n");
                    else
                        printf("Child has exited with exit status : %d\n", waitStatus);
                }
            }
        }
    }
}
	
