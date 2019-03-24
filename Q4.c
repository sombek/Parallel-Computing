/**
 * Q4 Tasks:
 * 1- Your program must create three threads.
 * 2- Each thread will start in a separate function than the other threads
 * 3- The general structure of the thread-startup function is that it will be in an infinite loop executing two statements:
 *    1- Report the thread number (first, second, third), along with the CPU it was scheduled on
 *    2- Sleeps for 2 seconds (sleep(2))
 *
 *
 *
 * **/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <sched.h>
//#include <zconf.h>

#define _GNU_SOURCE

int sched_getcpu();


void *th_func(void *param) {
    while (1) {
        printf("Thread No. %s, CPU Core: %d\n", param, sched_getcpu());
        sleep(1);
    }
}

void main() {
    pthread_t t1; // declare the thread
    pthread_t t2; // declare the thread
    pthread_t t3; // declare the thread
    pthread_t t4; // declare the thread
    pthread_t t5; // declare the thread
    pthread_t t6; // declare the thread

    pthread_create(&t1, NULL, th_func, (void *) "First"); // create the thread
    sleep(1/2);
    pthread_create(&t2, NULL, th_func, (void *) "Second"); // create the thread
    sleep(1/2);
    pthread_create(&t3, NULL, th_func, (void *) "Third"); // create the thread
    sleep(1/2);
    pthread_create(&t4, NULL, th_func, (void *) "Fourth"); // create the thread
    sleep(1/2);
    pthread_create(&t5, NULL, th_func, (void *) "Fifth"); // create the thread
    sleep(1/2);
    pthread_create(&t6, NULL, th_func, (void *) "Sixth"); // create the thread

    pthread_join(t1, NULL); // merge the worker_thread to the master
    pthread_join(t2, NULL); // merge the worker_thread to the master
    pthread_join(t3, NULL); // merge the worker_thread to the master
    pthread_join(t4, NULL); // merge the worker_thread to the master
    pthread_join(t5, NULL); // merge the worker_thread to the master
    pthread_join(t6, NULL); // merge the worker_thread to the master
}

