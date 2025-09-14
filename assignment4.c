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
        printf("Child (PID=%d) running grep...\n", getpid());
        execl("/bin/grep", "grep", "main", "test.txt", NULL);
        perror("execl failed for grep");
        exit(1);
    } else {
        wait(NULL);  
        printf("Parent process completed (PID=%d)\n", getpid());
    }

    return 0;
}

