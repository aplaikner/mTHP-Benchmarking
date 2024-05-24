#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE (5 * 1024 * 1024) // 5 MiB

int main() {
  char *addr;

  // Try to mmap anonymous memory with the special flag MAP_DYNAMICTHP
  addr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,  -1, 0);
  //addr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS | 0x021210000, -1, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }
   addr[0] = 'c';

  printf("Mmapped 5 MiB of anonymous memory at %p with MAP_DYNAMICTHP\n", addr);

  // Use the mapped memory here (accessing it like a regular array)

  // Unmap the memory
  munmap(addr, SIZE);

  return 0;
}
