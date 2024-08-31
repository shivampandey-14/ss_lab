/*
============================================================================
Name : 4.c
Author : Shivam Pandey
Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 17th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main() {
    const char *myfile = "4-test_file.txt";
    int pd = open(myfile, O_RDWR | O_EXCL | O_CREAT,0700);
    
    if (pd == -1) {
        if (errno == EEXIST) {
            printf("File already exists.\n");
        } else {
            perror("Failed to open file");
        }
        return -1;
    }
    
    printf("File opened with fd = %d\n", pd);
    close(pd);
    return 0;
}
