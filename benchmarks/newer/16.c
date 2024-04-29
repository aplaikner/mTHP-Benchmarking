#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int main() {
    sleep(1);
    pid_t p;
    char allocation[7000*1024];
    for (int i = 0; i < 7000*1024; i++) {
	    allocation[i] = 'a';
    }
    p = fork();
    if(p<0) {
	    printf("Fork failed!\n");
	    return 0;
    }
    if (p == 0) {
	    sleep(1);
	    printf("%ld\n", (long)getpid(), (long)getppid());
	    printf("Child!\n");
	    for (int i = 0; i < 7000*1024; i++) {
		    allocation[i] = 'b';
	    }
	    sleep(1);
	    //sleep(10000);
    }
    exit(0);
}

