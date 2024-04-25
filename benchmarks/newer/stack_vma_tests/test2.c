#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>



void *fun(void *ptr){
	sleep(1000);
	return 0;
}

int main() {
    sleep(20);
    pthread_t id;
    printf("Losgehts\n");
    pthread_create(&id, NULL, fun, NULL);
    pthread_join(id, NULL);
    sleep(1);
    exit(0);
}

