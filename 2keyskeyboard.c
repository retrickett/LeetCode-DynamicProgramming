#include <stdio.h>
#include <stdlib.h>


//Initially on a notepad only one character 'A' is present. 
//You can perform two operations on this notepad for each step:

//Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
//Paste: You can paste the characters which are copied last time.

//Given a number n. You have to get exactly n 'A' on the notepad by performing 
//the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

int minSteps(int n){
    if(n<=1){
        return 0;
    }
    else{
        int *arr=(int *)malloc((n+1)*sizeof(int));
        int i;

        //if a number is prime the minimum cost is the number
        //otherwise it is the minimum of the minimum cost of a factor pair
        //ex 6 = 3*2 or 2*3 or 1*6 or 6*1 so the cost is min of arr[3]+arr[2], arr[2]+arr[3], etc
        for(i=0;i<=n;i++){
            arr[i]=i;
            int j,div;
            for(j=i;j>0;j--){
                if(i%j==0){
                    div=i/j;
                    if((arr[div]+arr[j])<arr[i]){
                        arr[i]=arr[div]+arr[j];
                    }
                }
            }
        }
        return arr[n];
    }
}
