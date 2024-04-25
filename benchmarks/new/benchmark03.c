#include <stdio.h>
#include <alloca.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>
#include<time.h>
#include <signal.h>


void *myThreadFun(void *vargp) 
{    	
	char* allocation = alloca(2097152);
	srand(time(NULL));
	for(int i = 0; i<1000; i++) {
	      allocation[rand()%(2097152)] = 'a';
	      //allocation[rand()%(1)] = 'a';
	}	      
	sleep(1);
	exit(0);
} 
 int main() 
{ 
    sleep(1);
    pthread_t thread_id; 
    pthread_create(&thread_id, NULL, myThreadFun, NULL); 
    pthread_join(thread_id, NULL); 
    sleep(1);
    exit(0); 
}


