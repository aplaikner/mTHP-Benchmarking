#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main() {
    sleep(1);
    char* allocations[2];
    for (int j = 0; j < 2; j++) { 
	    sleep(0.2);
	    allocations[j]= alloca(3500 * 1024);
	    for(long i = 0; i < 3500*1024; i++) {
		allocations[j][i] = 'a';
	    }
	    sleep(0.2);
    }
    sleep(1);
    exit(0);
}

