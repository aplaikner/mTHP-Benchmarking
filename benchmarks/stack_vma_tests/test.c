#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main() {
	char *jeff = alloca(200 * 1024);
	for(int i = 0; i < 200*1024; ++i) {
		jeff[i] = 'a';
	}
	sleep(1000);
}
