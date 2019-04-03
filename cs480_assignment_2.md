# Question 7.22 (a) 

## First Cycle
``` js
Finish[P0] = F
Need ≤ Work
2 1 0 3 ≤ 0 3 0 1
Finish [P0] = F
``` 
``` js
Finish[P1] = F
Need ≤ Work
1 0 0 1 ≤ 0 3 0 1
Finish [P1] = F
``` 
``` js
Finish[P2] = F
Need[P2] ≤ Work
0 2 0 0 ≤ 0 3 0 1
Work = Work + Allocation[P2]  
Work = 0 3 0 1 + 3 1 2 1
Work = 3 4 2 2 
Finish [P2] = T
``` 
``` js
Finish[P3] = F
Need[P3] ≤ Work
4 1 0 2 ≤ 3 4 2 2
Finish [P3] = F
``` 
``` js
Finish[P4] = F
Need[P4]  ≤ Work
2 1 1 3 ≤ 3 4 2 2
Finish[p4] = F
``` 

## Second Cycle
``` js
Finish[P0] = F
Need[P0]  ≤ Work
2 1 0 3 ≤ 10 10  5  5  
Work = Work + Allocation[P0]  
Work = 10 10  5  5  + 3 0 1 4 
Work = 13 10  6  9
Finish [P0] = T
``` 
The final work matches the total 
``` 
<P1,P2,P3,P4,P0>
``` 
The work and need is not equal or the remaining processes there fore we got a `DeadLock`situation


# Question 7.23 

## First Cycle
`Total  = 12 12  8  10`

``` js
Finish[P0] = F
Need[P0]  ≤ Work
2 2 1 1 ≤ 3 3 2 1 
Work = Work + Allocation[P0]  
Work = 3 3 2 1 + 2 0 0 1
Work = 5 3 2 2 
Finish [P0] = T
``` 

``` js
Finish[P1] = F
Need[P1]  ≤ Work
2 1 3 1  ≤ 5 3 2 2 
Finish [P1] = F
``` 
``` js
Finish[P2] = F
Need[P2]  ≤ Work
0 2 1 3 ≤ 5 3 2 2
Finish [P2] = F
``` 
``` js
Finish[P3] = F
Need[P3]  ≤ Work
0 1 1 2 ≤ 5 3 2 2
Work = Work + Allocation[P3]  
Work = 5 3 2 2+ 1 3 1 2
Work = 6 6 3 4
Finish [P3] = T
``` 
``` js
Finish[P4] = F
Need[P4]  ≤ Work
2 2 3 3  ≤ 6 6 3 4
Work = Work + Allocation[P4]  
Work = 6 6 3 4 + 1 4 3 2
Work = 7  10  6  6  
Finish [P4] = T
``` 

## Second Cycle
``` js
Finish[P1] = F
Need[P1]  ≤ Work
2 2 1 1  ≤ 7  10  6  6  
Work = Work + Allocation[P1]  
Work = 7  10  6  6  + 3 1 2 1
Work = 10 11  8  7 
Finish [P1] = T
``` 

``` js
Finish[P2] = F
Need[P2]  ≤ Work
2 1 3 1 ≤ 10 11  8  7
Work = Work + Allocation[P2]  
Work = 10 11  8  7 + 2 1 0 3 
Work = 12 12  8  10 
Finish [P2] = T
``` 
The final work matches the total 
``` 
<P0,P3,P4,P1,P2>
``` 
