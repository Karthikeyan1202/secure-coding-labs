/* Deadlock example: two locks acquired in different orders (may deadlock) */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock1;
pthread_mutex_t lock2;

void *function1()
{
    printf("Function 1: Executing\n");
    pthread_mutex_lock(&lock1); /* step 1 */
    pthread_mutex_lock(&lock2); /* step 3 - potential deadlock */
    printf("Function 1: Inside critical section\n");
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void *function2()
{
    printf("Function 2: Executing\n");
    pthread_mutex_lock(&lock2); /* step 2 */
    pthread_mutex_lock(&lock1); /* may deadlock if function1 holds lock1 and function2 holds lock2 */
    printf("Function 2: Inside critical section\n");
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    pthread_create(&thread1, NULL, function1, NULL);
    pthread_create(&thread2, NULL, function2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    printf("Main: Program completed\n");
    return 0;
}
