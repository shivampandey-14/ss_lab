/*
============================================================================
Name : 1_a.c
Author : Shivam Pandey
Description :Create the following types of a files using (i) shell command (ii) system call
	     c. FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "my_fifo";

    int x=mkfifo(fifo_path, 7777); 
    if (x == -1) {
        perror("mkfifo");
        return 1;
    }
    return 0;
}

