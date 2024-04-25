#include <stdio.h>
#include <alloca.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>
#include<time.h>

int main() 
{ 
    sleep(1);
    char c = 'a';
    char* allocation = alloca(2097152 * 2 - 2097152/4);
    srand(time(NULL));
    for(int i = 0; i<100000; i++) {
      allocation[rand()%(2097152 * 2 - 2097152/4)] = c;
    }	      
    sleep(1);
}


