#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/mman.h>


int main() {
	printf("%ld\n", (long)getpid());
	char *allocation = mmap(NULL,(4096<<9)*3, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	char *allocation2 = mmap(NULL,(4096<<9)*3, PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0);
	madvise(allocation, 4096*513, MADV_POPULATE_WRITE);
	unsigned long r =  (4096<<9)*2;
	sleep(5);
	//madvise(allocation+(4096<<9), 4096*4, MADV_POPULATE_WRITE);
	printf("%ld\n", (long)getpid());
	sleep(5);
	madvise(allocation+(4096<<9)*2, 4096*4, MADV_POPULATE_WRITE);
	printf("%ld\n", (long)getpid());
	//madvise(allocation2, 4096*513, MADV_POPULATE_WRITE);
/*	
	for(int i = r; i<r+4096; i++) {
		allocation[i] = 'a';
	}
	*/
	allocation[0] = 'a';
	allocation[(4096<<9)-1] = 'b';
	allocation[(4096<<9)*2+1] = 'c';
	sleep(10000);

}
