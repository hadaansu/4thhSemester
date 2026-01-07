#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

// Thread function
void* thread_function(void* arg) {
    printf("Thread running in process PID: %d\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    // Create process
 //   pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    // Both parent and child will execute this code
    if (pid == 0) {
        printf("Child process started. PID: %d\n", getpid());
    } else {
        printf("Parent process started. PID: %d\n", getpid());
    }

    // Create thread inside each process
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        printf("Thread creation failed in PID: %d\n", getpid());
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    if (pid == 0) {
        printf("Child process ending. PID: %d\n", getpid());
    } else {
        printf("Parent process ending. PID: %d\n", getpid());
    }

    return 0;
}
