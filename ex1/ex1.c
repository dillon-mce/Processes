// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// It is the same value as it was on the parent process when fork was called.
// What happens to the variable when both the child and parent change the value of x?
// If the variable is changed, it affects only that process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  

int main(void)
{
    // Your code here
    int x = 2;
    int rc = fork();
    printf("x has the value %d on process %d\n", x, (int) getpid());
    if (rc == 0) {
        x = 5;
        printf("x has the value %d on process %d\n", x, (int) getpid());
    } else {
        int wc = waitpid(rc, NULL, 0);  
        printf("x has the value %d on process %d\n", x, (int) getpid());
    }
    return 0;
}
