#include <stdio.h>
#include <alloca.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>
#include<time.h>

void *myThreadFun(void *vargp) 
{    	//int a = 5;
	char* allocation = alloca(2097152);
    	sleep(2);
	allocation[500] = 'a';
    	//allocation[501] = 'a';
   	//allocation[1000000] = 'a';
  
	sleep(5);
	//char* allocation = alloca(2097152);
	//char* allocation = alloca(1);
	//srand(time(NULL));
	//char* mallocation = malloc(8000000);
	//int counter = 0;
	//while(1) {
	//long index = rand() % 1999999;
	//long index = rand() % (57-48+1) + 48;
	//allocation[index] = rand() % (57-48+1) + 48;
	//mallocation[index] = 12;
	//printf("My number is: %c\n", index);
	//sleep(1);
	//}
} 
   
int main() 
{ 
//    char* allocation = alloca(2097152);
 //   allocation[500] = 'a';
  //  allocation[1000000] = 'a';
    pthread_t thread_id; 
    printf("Before Thread\n"); 
    char c;
    scanf("%c", &c);
    pthread_create(&thread_id, NULL, myThreadFun, NULL); 
    pthread_join(thread_id, NULL); 
    printf("After Thread\n"); 
    exit(0); 
}


