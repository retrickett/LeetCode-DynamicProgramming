#include <stdio.h>
#include <stdlib.h>

//A robot is located at the top-left corner of a m x n grid 
//(marked 'Start' in the diagram below).

//The robot can only move either down or right at any point in time. 
//The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

//How many possible unique paths are there?

int uniquePaths(int m, int n){
    int a[m+1][n+1];
    int i,j;
    //make table of all zeros, one row/col larger than m and n
    for (i=0;i<m+1;i++){
        for (j=0;j<n+1;j++){
            a[i][j]=0;
        }
    }
    

    for (i=1;i<m+1;i++){
        a[i][1]=1;
    }
    for (i=1;i<n+1;i++){
        a[1][i]=1;
   }
    
    //number of paths to a square i is the number of paths from the square above it plus the number
    //of paths from the square to the left
    //because you can only travel down or to the right
    for (i=2;i<m+1;i++){
        for (j=2;j<n+1;j++){
            a[i][j]=a[i-1][j]+a[i][j-1]; 
        }
    }
    

    
    
    return a[m][n];
}