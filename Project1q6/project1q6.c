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
int array[40];

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


void *sum() {
    int sum = 0;
    for (int i = 0; i < 40; i++)
        sum += array[i];
    return (void *) sum;
}

void *mult() {
    long long mult = 1;
    for (int i = 0; i < 40; i++)
        mult = mult * array[i];
    return (void *) mult;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: a.out <file name>\n");
        return -1;
    }
    readfile(argv[1]);

//    for (int i = 0; i < 40; i++)
//        printf("%d + ", array[i]);

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, mult, NULL);

    void *sum_res;
    void *mult_res;

    pthread_join(t1, &sum_res); // merge the worker_thread to the master
    pthread_join(t2, &mult_res); // merge the worker_thread to the master

    printf("Sum Result: %d\n", (int) sum_res);
    printf("Multiplication Result: %lld\n", (long long) mult_res);

    return 0;
}

