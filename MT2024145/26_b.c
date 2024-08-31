/*
-------------------------------------------------------
-------------------------------------------------------
Name - 25.c
Author - Shivam PAndey
Description - Write a program to execute an executable program.
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date-31-8-24
-------------------------------------------------------
-------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	execl("./b","e",(char*)NULL);
	return 0;
}	
