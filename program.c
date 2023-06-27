#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <time.h>

int main() {
    // Get ID of the process
    int pid = getpid();
    printf("Process ID: %d\n", pid);

    printf("Sleeping for 15 seconds...\n");
    sleep(15);
    printf("\n");

    // Memory map an empty page (VSZ or virtual memory will increase)
    void* addr = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }
    
    printf("Memory mapping an empty page (mmap)\n");
    printf("Sleeping for 15 seconds...\n");
    sleep(15);
    printf("\n");

    // Writing data into the page (RSS or physical memory will increase in some cases, in some not)
    int* data = (int*)addr;
    *data = 122;

    printf("Writing data into the page\n");
    printf("Sleeping for 15 seconds...\n");
    sleep(15);
    printf("\n");

    // Unmapping the memory
    if (munmap(addr, getpagesize()) == -1) {
        perror("munmap failed");
        return 1;
    }
	
    printf("Unmapping the memory\n");
    printf("Sleeping for 15 seconds...\n");
    sleep(15);
    printf("\n");

    printf("Exiting\n");

    return 0;
}


