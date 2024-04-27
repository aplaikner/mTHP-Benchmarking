#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main() {
	char jeff[122 * 1024 + 1];
	for(int i = 0; i < 122*1024 + 1; i++) {
		jeff[i] = 'a';
	}
	sleep(1000);
}
