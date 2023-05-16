#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int fd, num_bytes;
    char buffer[BUFFER_SIZE];

    // Create the file using the open() system call
    fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read data from the user and write it to the file using the write() system call
    printf("Enter some data to write to the file:\n");
    num_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
    if (num_bytes == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    if (write(fd, buffer, num_bytes) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    // Re-open the file for reading using the open() system call
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the data from the file using the read() system call and print it to the console
    printf("The contents of the file are:\n");
    while ((num_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, num_bytes) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
    if (num_bytes == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    return 0;
}
