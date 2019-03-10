#include <pthread.h>
#include <stdio.h>


struct char_print {
    char character;
    int count;
};

void *print(void *parameters) {
    struct char_print *p;
    p = (struct char_print *) parameters;
    int i;
    for (i = 0; i < p->count; ++i)
        fputc(p->character, stderr);

    pthread_exit(NULL);
}

int main() {
    pthread_t t1_id; // declare thread 1
    pthread_t t2_id; // declare thread 2

    struct char_print t1_args; // declare thread argument type of char_print
    struct char_print t2_args; // declare thread argument type of char_print

    t1_args.character = '1';  // initialize the thread argument
    t1_args.count = 60; // initialize the thread argument

    pthread_create(&t1_id, NULL, print, (void *) &t1_args); // create the thread and pass the arguments object
    pthread_join(t1_id, NULL); // wait then join the worker thread to the master

    t2_args.character = '0'; // initialize the second thread argument
    t2_args.count = 100; // initialize the second thread argument

    pthread_create(&t2_id,
                   NULL,
                   print,
                   (void *) &t2_args); // create the second thread and pass the thread argument object
    pthread_join(t2_id, NULL); // wait then joint the second worker thread to the master thread
}
