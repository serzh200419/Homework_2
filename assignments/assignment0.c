#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Process started: PID=%d, Parent PID=%d\n", getpid(), getppid());

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }
    printf("After 1st fork: PID=%d, Parent PID=%d\n", getpid(), getppid());

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }
    printf("After 2nd fork: PID=%d, Parent PID=%d\n", getpid(), getppid());

    pid_t pid3 = fork();
    if (pid3 < 0) {
        perror("fork failed");
        exit(1);
    }
    printf("After 3rd fork: PID=%d, Parent PID=%d\n", getpid(), getppid());

    return 0;
}

