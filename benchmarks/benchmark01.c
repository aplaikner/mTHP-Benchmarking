#include <stdio.h>
#include <alloca.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>


int main() {
	char* allocation = alloca(2220000);
	srand(time(NULL));
	char* mallocation = malloc(8000000);
	int counter = 0;
	while(counter++!=200000) {
	long index = rand() % 1999999;
	allocation[index] = rand() % (57-48+1) + 48;
	mallocation[index] = 12;
	sleep(40);
	printf("My number is: %c\n", allocation[index]);
	//sleep(1);
	}

return 0;

}
