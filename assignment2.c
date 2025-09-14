#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed for first child");
        exit(1);
    }

    if (pid1 == 0) {
        printf("First child (PID=%d) running ls...\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl failed for ls"); 
        exit(1);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed for second child");
        exit(1);
    }

    if (pid2 == 0) {
        printf("Second child (PID=%d) running date...\n", getpid());
        execl("/bin/date", "date", NULL);
        perror("execl failed for date");
        exit(1);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("Parent process done (PID=%d)\n", getpid());
    return 0;
}

