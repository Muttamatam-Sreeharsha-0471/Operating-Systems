#include <stdio.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 100

// Function to calculate the number of disk I/O operations for contiguous allocation
int contiguous_allocation(int position) {
    int start_block = position;
    int end_block = NUM_BLOCKS;
    int num_operations = 0;
    
    // If the block is being added at the beginning, only one write operation is needed
    if (position == 0) {
        num_operations = 1;
    }
    else {
        // Otherwise, we need to move all the blocks from the start to the end of the file
        num_operations = 1 + ((end_block - start_block + 1) * 2);
    }
    
    return num_operations;
}

// Function to calculate the number of disk I/O operations for linked allocation
int linked_allocation(int position) {
    int num_operations = 0;
    
    // If the block is being added at the beginning, only one write operation is needed
    if (position == 0) {
        num_operations = 1;
    }
    else {
        // Otherwise, we need to traverse the linked list to find the block before the position
        // and update its pointer to point to the new block
        num_operations = 2;
        
        // Traverse the linked list
        int current_block = 0;
        while (current_block < position - 1) {
            current_block++;
            num_operations += 2;
        }
    }
    
    return num_operations;
}

// Function to calculate the number of disk I/O operations for indexed allocation
int indexed_allocation(int position) {
    int num_operations = 0;
    int index_block_size = BLOCK_SIZE / sizeof(int);
    
    // If the block is being added at the beginning, only one write operation is needed
    if (position == 0) {
        num_operations = 1;
    }
    else {
        // Otherwise, we need to update the index block to point to the new block
        num_operations = 2;
        
        // Traverse the index block to find the block before the position
        int current_block = 0;
        while (current_block < position - 1) {
            current_block += index_block_size;
            num_operations++;
        }
        
        // Update the pointer in the index block to point to the new block
        num_operations++;
    }
    
    return num_operations;
}

int main() {
    int position;
    printf("Enter the position where the block needs to be added (0-99): ");
    scanf("%d", &position);
    
    int num_contiguous_operations = contiguous_allocation(position);
    printf("Number of disk I/O operations for contiguous allocation: %d\n", num_contiguous_operations);
    
    int num_linked_operations = linked_allocation(position);
    printf("Number of disk I/O operations for linked allocation: %d\n", num_linked_operations);
    
    int num_indexed_operations = indexed_allocation(position);
    printf("Number of disk I/O operations for indexed allocation: %d\n", num_indexed_operations);
    
    return 0;
}
