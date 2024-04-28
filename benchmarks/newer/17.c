#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int main() {
    sleep(1);
    char allocation[8191*1024];
    sleep(1);
    exit(0);
}

