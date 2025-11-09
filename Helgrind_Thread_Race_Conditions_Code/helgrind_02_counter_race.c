/* Threads sharing a counter WITHOUT synchronization (racy example) */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 2

int counter = 0;

void *print_hello(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Thread number \t %ld sleeps %ld seconds...\n", tid, tid);
    counter++; /* RACE: increment without lock */
    sleep(tid);
    printf("Thread number \t %ld exiting \n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    long array_ids[NUM_THREADS];
    int rc = 0;
    long t;
    for (t = 0; t < NUM_THREADS; t++) {
        array_ids[t] = t;
        printf("In main: creating thread %ld\n", array_ids[t]);
        rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    printf("counter is %i \n", counter);
    return 0;
}
