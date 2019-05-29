// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// it appears so.
// returned by `fopen()`? What happens when they are written to the file concurrently?
// it looks like they just add text in whatever order the code happens to get hit.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE *textFile = fopen("text.txt", "r+");

    printf("%p\n", textFile);

    int rc = fork();

    if (rc == 0) {
        char *text = "This is a test string from the child process.\n";
        fwrite(text, 1, strlen(text), textFile);
    } else {
        char *text = "This is a test string from the parent process.\n";
        fwrite(text, 1, strlen(text), textFile);
        fclose(textFile);
    }
    
    return 0;
}
