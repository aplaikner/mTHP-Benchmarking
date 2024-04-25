#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main() {
    sleep(1);
    char* allocation = alloca(5000 * 1024);
    for(long i = 0; i < 5000*1024; i++) {
	allocation[i] = 'a';
    }
    sleep(1);
    exit(0);
}

