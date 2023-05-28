#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {

    // Get ID of the process
    int pid = getpid();
    printf("Process ID: %d\n", pid);

    // Memory map an empty page (virtual memory will increase)
    void* addr = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    // Writing data into the page (physical memory will therefore increase)
    int* data = (int*)addr;
    *data = 122;

    // Pause for 1 hour (3600 seconds)
    sleep(3600);

    // Unmapping the memory
    if (munmap(addr, getpagesize()) == -1) {
        perror("munmap failed");
        return 1;
    }

    return 0;
}

