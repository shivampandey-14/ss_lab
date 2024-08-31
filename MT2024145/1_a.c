/*
============================================================================
Name : 1_a.c
Author : Shivam Pandey
Description :Create the following types of a files using (i) shell command (ii) system call
	     a. soft link (symlink system call) 
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *c = "1-a-target_file.txt";
    char *c1 = "soft_link.txt";
    int x=symlink(c,c1);
    if (x!=0) {
        perror("link");
        return 1;
    }
    return 0;
}

