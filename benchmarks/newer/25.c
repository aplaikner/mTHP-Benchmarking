#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int main() {
    srand(time(0));
    //sleep(1);
    pid_t p;
    char allocation[7000*1024];
    for (int i = 0; i < 7000*1024; i++) {
	    allocation[i] = (rand() % (7000*1024));
    }
//    printf("REAL PARENT:%ld\n", (long)getpid());;
    p = fork();
    if(p<0) {
	    printf("Fork failed!\n");
	    return 0;
    }
    // sleep if parent
    if(p!=0) {
	    sleep(2);
    }
    if (p == 0) {
	    printf("REAL CHILD:%ld\n", (long)getpid());;
	    sleep(20);

	    for (int i = 0; i < 50; i++) {
	    	printf("%c\n", allocation[(rand() % (7000*1024))]);
            }
    }
    sleep(2);
    exit(0);
}

