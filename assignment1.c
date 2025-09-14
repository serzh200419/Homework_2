#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process running ls command (PID=%d)\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);  
        perror("execl failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent process done (PID=%d)\n", getpid());
    }

    return 0;
}

