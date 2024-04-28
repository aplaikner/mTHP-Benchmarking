#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void *fun(void *ptr){
	char* allocation = alloca(6500 * 1024);
	sleep(1);
	return 0;
}

int main() {
    sleep(1);
    pthread_t id;
    pthread_create(&id, NULL, fun, NULL);
    pthread_join(id, NULL);
    sleep(1);
    exit(0);
}

