#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main() {
    sleep(1);
    char* allocations[3];
    for (int j = 0; j < 3; j++) { 
	    sleep(0.2);
	    allocations[j]= alloca(2400 * 1024);
	    for(long i = 0; i < 2400*1024; i++) {
		allocations[j][i] = 'a';
	    }
	    sleep(0.2);
    }
    sleep(1);
    exit(0);
}

