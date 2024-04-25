#include <stdio.h>
#include <alloca.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>
#include<time.h>

void *myThreadFun(void *vargp) 
{    	
	char* allocation = alloca(2097152);
    	sleep(2);
	//char* allocation = alloca(1);
    	sleep(2);
	srand(time(NULL));
	for(int i = 0; i<10000; i++) {
	      allocation[rand()%(2097152)] = 'd';
	      //allocation[rand()%(1)] = 'a';
	}	      
	sleep(5);
} 
   
int main() 
{ 
    char c;
    scanf("%c", &c);
    char* allocation = alloca(2097152);
	srand(time(NULL));
	for(int i = 0; i<10000; i++) {
	      allocation[rand()%(2097152)] = 'a';
	}	      
	printf("Wrote first part\n");
	sleep(5);
    char* allocation2 = alloca(2097152);
	for(int i = 0; i<10000; i++) {
	      allocation2[rand()%(2097152)] = 'b';
	}	      
	printf("Wrote second part\n");
	sleep(5);
    char* allocation3 = alloca(2097152);
	for(int i = 0; i<10000; i++) {
	      allocation3[rand()%(2097152)] = 'c';
	}	      
	printf("Wrote third part\n");
	sleep(5);
    pthread_t thread_id; 
    printf("Before Thread\n"); 
    pthread_create(&thread_id, NULL, myThreadFun, NULL); 
    pthread_join(thread_id, NULL); 
    printf("After Thread\n"); 
    exit(0); 
}


