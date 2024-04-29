#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/resource.h>


int main() {
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    printf("Current stack size limit: %ld KB\n", rlim.rlim_cur / 1024);
    rlim.rlim_cur = 8192000/2; // Set to 8 MB
    //setrlimit(RLIMIT_STACK, &rlim);
    printf("New stack size limit: %ld KB\n", rlim.rlim_cur / 1024);
    sleep(1);
    char allocation[15000*1024];
    sleep(1);
    exit(0);
}


