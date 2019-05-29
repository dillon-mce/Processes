// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    int pipe1[2];

    pipe(pipe1);

    int cp = fork();

    if (cp == 0) {
        close(pipe1[0]);
        write(pipe1[1], msg1, MSGSIZE);
        write(pipe1[1], msg2, MSGSIZE);
        write(pipe1[1], msg3, MSGSIZE);
        close(pipe1[1]);
    } else {
        close(pipe1[1]);
        char buffer[MSGSIZE];
        for (int i = 0; i < 3; i++) {
            read(pipe1[0], buffer, MSGSIZE);
            printf("%s\n", buffer);
        }
        close(pipe1[0]);
    }

    return 0;
}
