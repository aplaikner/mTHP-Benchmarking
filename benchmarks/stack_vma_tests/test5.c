#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>



void *fun(void *ptr){
    	char allocation[15000*1024];
	sleep(5000);
	return 0;
}

int main() {
    pthread_t id;
    pthread_create(&id, NULL, fun, NULL);
    pthread_join(id, NULL);
    sleep(1);
    exit(0);
}

