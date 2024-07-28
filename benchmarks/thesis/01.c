#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 100
#define THREADS 100

void *fun(void* args){
	srand(time(NULL));
	char buffer[SIZE];
	for (int i = 0; i < SIZE; i++) {
		buffer[i] = rand()%60;
	}
	sleep(3);
	return NULL;
}

int main() { 
    sleep(1);
    pthread_t arr[THREADS];
    for (int i = 0; i < THREADS; i++) {
	pthread_create(&arr[i], NULL, fun, NULL);
    }
    for (int i = 0; i < THREADS; i++) {
    	pthread_join(arr[i], NULL);
    }
    sleep(1);
    return 0;
}

