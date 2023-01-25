#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // child process
        char *args[] = {"/usr/bin/gedit", NULL};
        execvp(args[0], args);
        exit(0);
    } else if (pid > 0) {
        // parent process
        printf("Child process created with PID %d\n", pid);
    } else {
        // fork failed
        printf("Fork failed\n");
    }

    return 0;
}
