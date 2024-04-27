#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main() {
	int what;
	scanf("%d", &what);
	char jeff[what*1024-sizeof(what)];
	for(int i = 0; i < what*1024-sizeof(what); i++) {
		jeff[i] = 'a';
	}
	sleep(5000);
}
