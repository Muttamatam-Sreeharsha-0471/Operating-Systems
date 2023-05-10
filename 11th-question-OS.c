#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid[4];
    int i;

    for (i = 0; i < 4; i++) {
        pid[i] = fork();

        if (pid[i] == 0) {
            // Child process
            switch (i) {
                case 0:
                    // Print odd numbers
                    printf("Odd numbers (PID %d):\n", getpid());
                    for (int j = 1; j <= 10; j += 2) {
                        printf("%d ", j);
                    }
                    printf("\n");
                    break;
                case 1:
                    // Print even numbers
                    printf("Even numbers (PID %d):\n", getpid());
                    for (int j = 2; j <= 10; j += 2) {
                        printf("%d ", j);
                    }
                    printf("\n");
                    break;
                case 2:
                    // Print multiples of 3
                    printf("Multiples of 3 (PID %d):\n", getpid());
                    for (int j = 3; j <= 30; j += 3) {
                        printf("%d ", j);
                    }
                    printf("\n");
                    break;
                case 3:
                    // Print multiples of 5
                    printf("Multiples of 5 (PID %d):\n", getpid());
                    for (int j = 5; j <= 50; j += 5) {
                        printf("%d ", j);
                    }
                    printf("\n");
                    break;
            }
            return 0;
        }
    }

    // Parent process
    for (i = 0; i < 4; i++) {
        printf("Child process %d has PID %d\n", i+1, pid[i]);
    }

    return 0;
}
