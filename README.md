# Parallel-Computing
Computer Architecture and Parallel Computing Assignments &amp; Project

# Q1
The expected output for EX7.3 is `1111111111111111111111111111111111111111111111111111111111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000`

# Q2
As I recompile I get different outputs: 
`1�`
`1�����`
`1���`
sometime an empty out put

# Q3 
I believe after we comment `pthread_join` the master thread is not waiting for the response from the worker which is 
passed in the `pthread_create` function. So the application runs the two threads and terminate the master thread 
without waiting the workers to join in the master, which causes this inconsistent outputs.

# Q4 
The shown output is a snippet of the output console which keeps printing infinitely until aborted manually
``` text
 Thread No. Second, CPU Core: 1
 Thread No. First, CPU Core: 1
 Thread No. Fourth, CPU Core: 1
 Thread No. Sixth, CPU Core: 1
 Thread No. Third, CPU Core: 0
 Thread No. Fifth, CPU Core: 0
 Thread No. Second, CPU Core: 1
 Thread No. First, CPU Core: 1
 Thread No. Fourth, CPU Core: 1
 Thread No. Sixth, CPU Core: 1
 Thread No. Third, CPU Core: 0
 Thread No. Fifth, CPU Core: 0
 ```
 
 
 # Q5 
The output:
```text
Reading file: ../Project1q5/input.txt
Reading file Complete, integers stored in array.
Thread 1 Sum: 5670
Thread 2 Sum: 5281
Thread 3 Sum: 4997
Thread 4 Sum: 5254
Total Sum is: 21202
```

# Q6
The output:
```text
Reading file: ../Project1q6/input.txt
Reading file Complete, integers stored in array.
Sum Result: 93
Multiplication Result: 14631321600
```
