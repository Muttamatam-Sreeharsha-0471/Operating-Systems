#include <stdio.h>
#include <stdint.h>

#define DISK_BLOCK_SIZE 8192 
#define POINTER_SIZE 4 

#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (DISK_BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (DISK_BLOCK_SIZE / POINTER_SIZE * DISK_BLOCK_SIZE / POINTER_SIZE)
#define TRIPLE_INDIRECT_BLOCKS (DISK_BLOCK_SIZE / POINTER_SIZE * DISK_BLOCK_SIZE / POINTER_SIZE * DISK_BLOCK_SIZE / POINTER_SIZE)

uint64_t calculateMaxFileSize() {
    uint64_t maxFileSize = 0;

    maxFileSize += DIRECT_BLOCKS * DISK_BLOCK_SIZE; 
    maxFileSize += SINGLE_INDIRECT_BLOCKS * DISK_BLOCK_SIZE; 
    maxFileSize += DOUBLE_INDIRECT_BLOCKS * DISK_BLOCK_SIZE * SINGLE_INDIRECT_BLOCKS;
    maxFileSize += TRIPLE_INDIRECT_BLOCKS * DISK_BLOCK_SIZE * SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS; 

    return maxFileSize;
}

int main() {
    uint64_t maxFileSize = calculateMaxFileSize();

    printf("Maximum file size: %lu bytes\n", maxFileSize);

    return 0;
}