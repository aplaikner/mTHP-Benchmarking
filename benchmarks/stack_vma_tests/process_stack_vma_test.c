#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main() {
    //printf("%ld\n", (long)getpid());
    /*
    char allocation[1024*50000];
    
    allocation[100] = 69;
    allocation[200] = allocation[100];
    */
    int size=500;
    //scanf("%d\n", &size);
    char* allocation2 = malloc(1024*size);
    allocation2[0] = 21;
    allocation2[1] = allocation2[0];
    
    sleep(20);
    exit(0);
}

