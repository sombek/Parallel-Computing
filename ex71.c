#include <stdio.h>
#include <pthread.h>


int glob_data = 5;

void *th_func(void *p) {

    printf("Thread here. Global data was %d.\n", glob_data);
    glob_data = 15;
    printf("Thread Again. Global data was now %d.\n", glob_data);
}

void main() {
    pthread_t t1; // declare the thread
    pthread_create(&t1, NULL, th_func, NULL); // create the thread
    printf("Main here. Global data = %d\n", glob_data); // print global data before merge thread
    glob_data = 10; // update the glob_data explicitly
    pthread_join(t1, NULL); // merge the worker_thread to the master
    printf("End of program. Global data = %d\n", glob_data); // print glob_data after merging the thread
}

