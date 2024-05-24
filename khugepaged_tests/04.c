#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/mman.h>


int main() {
	printf("%ld\n", (long)getpid());
	char *allocation = mmap(NULL,(4096<<9)*3, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0);
	//char *allocation2 = mmap(NULL,(4096<<9)*3, PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	//madvise(allocation, 4096*4, MADV_POPULATE_WRITE);
	//madvise(allocation+4096*4, 4096*(512-4), MADV_POPULATE_WRITE);
	//sleep(5);
	//madvise(allocation+(4096<<9), 4096*1, MADV_POPULATE_WRITE);
	//sleep(5);
	//allocation[(4096<<9)+400*4096] = 'a';
	//sleep(10);
	//madvise(allocation+(4096<<9)*2, 4096*511, MADV_POPULATE_WRITE);
	//allocation[(4096<<9)*2] = 'b';
//	allocation2[0] = 'f';
	sleep(10000);

}
