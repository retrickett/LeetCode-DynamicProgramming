#include <stdio.h>
#include <stdlib.h>

//You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

int climbStairs(int n){
    int *a=(int *)malloc((n+1)*sizeof(int));
    int i=0;
    for(i=0;i<n+1;i++){
        a[i]=0;
    }
    
    if (n>0){
        a[1]=1;
    }
    
    if (n>1){
        a[2]=2;
        for (i=3;i<=n;i++){
            //get number of ways you can get to stair i by taking 1 step a[i-1] or by taking 2 steps a[i-1]
            a[i]=(a[i-1]+a[i-2]);
        }
    }

    
    return a[n];
}
