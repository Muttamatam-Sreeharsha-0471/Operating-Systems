#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

// Function to generate the Fibonacci series
void generateFibonacci(int n) {
    int prev = 0, curr = 1;
    printf("Fibonacci Series: %d %d ", prev, curr);

    for (int i = 3; i <= n; i++) {
        int next = prev + curr;
        printf("%d ", next);

        prev = curr;
        curr = next;
    }

    printf("\n");
}

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d)\n", getpid());
        int n = 10; // Number of Fibonacci series terms
        generateFibonacci(n);
    } else {
        // Parent process
        printf("Parent process (PID: %d)\n", getpid());

        // Wait for the child process to finish
        wait(&status);

        printf("Prime Numbers: ");
        for (int i = 2; i <= 20; i++) {
            if (isPrime(i))
                printf("%d ", i);
        }

        printf("\n");
    }

    return 0;
}
