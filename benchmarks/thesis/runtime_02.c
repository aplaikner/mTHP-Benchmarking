#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>

#define SIZE 2048 * 1024 * 3 - 200 * 1024 
#define THREADS 1

void *fun(void* args){
	srand(time(NULL));
	char buffer[SIZE];
	for (int i = 0; i < SIZE; i++) {
		buffer[i] = rand() % 60;
	}
	return NULL;
}

int main() { 
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    pthread_t arr[THREADS];
    for (int i = 0; i < THREADS; i++) {
	pthread_create(&arr[i], NULL, fun, NULL);
    }
    for (int i = 0; i < THREADS; i++) {
    	pthread_join(arr[i], NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    uint64_t diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("%llu,\n", (long long unsigned int) diff);
    return 0;
}

