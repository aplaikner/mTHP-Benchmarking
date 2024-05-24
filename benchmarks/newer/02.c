#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void *fun(void *ptr){
	//sleep(60);
	char allocation[2038*1024];
	for(int i = 0; i < 2038*1024; i++) {
		allocation[i]='a';
	}
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

