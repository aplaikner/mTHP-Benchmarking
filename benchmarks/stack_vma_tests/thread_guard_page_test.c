#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void *fun(void *ptr){
	sleep(20);
	return 0;
}

int main() {
    printf("%ld\n", (long)getpid());
    sleep(1);
    pthread_t id;
    printf("%x\n", &id);
    pthread_create(&id, NULL, fun, NULL);
    pthread_join(id, NULL);
    sleep(1);
    exit(0);
}

