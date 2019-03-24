/*

CSE 480 : Project 1 : Question 5

This is the starting skeleton code.
The function to read a file has already been given.

Another Debug function called testSum has been given for testing,
to check the value of the sum against the values the threads calculate.
(This function is purely for testing and debugging only)

Split the "array" of 1000 elements into 4 portions and give each 
portion to one thread. So Thread 1 will get 250 elements , Thread 2 the next 250 and so on. 
In the end when all four threads are done , add up their sums to get the final total sum of all 1000 elements.
Print the sum.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The array that holds the data
int array[1000];


int array_1[250] = {0};
int array_2[250] = {0};
int array_3[250] = {0};
int array_4[250] = {0};


void testSum() {
    int sum = 0;
    int j;

    for (j = 0; j < 1000; j++) {
        sum += array[j];
    }

    printf("Testing without threads, Sum is : %d \n", sum);

}

// This function reads a file with 1000 integers, an integer is stored in 
// each line.The function stores the integers in the array

void readfile(char *file_name) {

    char ch;

    FILE *fp;


    fp = fopen(file_name, "r"); // read mode

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }


    char line[5]; /* line size */

    int i = 0;

    printf("Reading file: ");
    fputs(file_name, stdout);
    printf("\n");


    while (fgets(line, sizeof line, fp) != NULL) /* read a line */
    {
        if (i < 1000) {
            array[i] = atoi(line);
        }

        //debug code
        //fputs ( line, stdout ); /* write the line */
        i++;
    }


    // debug code 
    //printf("i is : %d \n",i);

    fclose(fp);

    printf("Reading file Complete, integers stored in array.\n\n");

}


void *sum(void *arg) {

    int sum = 0;
    int i = 0;
    for (i = 0; i < 250; i++) {
        if (arg == (void *) 1)
            sum += array_1[i];
        if (arg == (void *) 2)
            sum += array_2[i];
        if (arg == (void *) 3)
            sum += array_3[i];
        if (arg == (void *) 4)
            sum += array_4[i];
    }
    return (void *) sum;
}

void push(int arg, int element) {
    if (arg == 1)
        for (int i = 0; i < 250; ++i)
            if (array_1[i] == 0) {
                array_1[i] = element;
                break;
            }
    if (arg == 2)
        for (int i = 0; i < 250; ++i)
            if (array_2[i] == 0) {
                array_2[i] = element;
                break;
            }
    if (arg == 3)
        for (int i = 0; i < 250; ++i)
            if (array_3[i] == 0) {
                array_3[i] = element;
                break;
            }
    if (arg == 4)
        for (int i = 0; i < 250; ++i)
            if (array_4[i] == 0) {
                array_4[i] = element;
                break;
            }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: a.out <file name>\n");
        return -1;
    }
    readfile(argv[1]);

    //Debug code for testing only
//    testSum();


    for (int i = 0; i < 250; i++)
        push(1, array[i]);

    for (int i = 250; i < 500; i++)
        push(2, array[i]);

    for (int i = 500; i < 750; i++)
        push(3, array[i]);

    for (int i = 750; i < 1000; i++)
        push(4, array[i]);

    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;

    pthread_create(&t1, NULL, sum, (void *) 1);
    pthread_create(&t2, NULL, sum, (void *) 2);
    pthread_create(&t3, NULL, sum, (void *) 3);
    pthread_create(&t4, NULL, sum, (void *) 4);

    void *sum1;
    void *sum2;
    void *sum3;
    void *sum4;

    pthread_join(t1, &sum1); // merge the worker_thread to the master
    pthread_join(t2, &sum2); // merge the worker_thread to the master
    pthread_join(t3, &sum3); // merge the worker_thread to the master
    pthread_join(t4, &sum4); // merge the worker_thread to the master

    printf("Thread 1 Sum: %d\n", (int) sum1);
    printf("Thread 2 Sum: %d\n", (int) sum2);
    printf("Thread 3 Sum: %d\n", (int) sum3);
    printf("Thread 4 Sum: %d\n\n", (int) sum4);

    int total = (int) sum1 + (int) sum2 + (int) sum3 + (int) sum4;
    printf("Total Sum is: %d\n", total);
    return 0;
}

