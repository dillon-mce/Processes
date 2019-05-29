// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    int rc = fork();
    if (rc == 0) {
        char *args[0];
        execv("/bin/ls", args);
    } else {
        int wc = waitpid(rc, NULL, 0);
    }
    return 0;
}
