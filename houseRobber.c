#include <stdio.h>
#include <stdlib.h>
 //You are a professional robber planning to rob houses along a street. 
 //Each house has a certain amount of money stashed, the only constraint stopping you
 // from robbing each of them is that adjacent houses have security system connected and it
 // will automatically contact the police if two adjacent houses were broken into on the same night.

 //Given a list of non-negative integers representing the amount of money of each house, 
 //determine the maximum amount of money you can rob tonight without alerting the police.

int rob(int* nums, int numsSize){
    if (numsSize>0){
    int *max= (int *)malloc(numsSize*sizeof(int));
    int i;
    for(i=0;i<numsSize;i++){
        max[i]=0;
    }
        
    max[0]=nums[0];
    
    if (numsSize>1){
      max[1]=nums[1];
      if (numsSize>2){
          max[2]=max[0]+nums[2];
      }
    
        for (i=3;i<numsSize;i++){
            //cant rob adjacent house a[i-1] but you can rob 2 or 3 houses away
            //don't need to check more than 2 or 3 houses away because these maximum robbings are absorbed
            //make the max robbing at house i the maximumum of two or three houses away plus the value at house i
            if ((max[i-2]+nums[i])>(max[i-3]+nums[i])){
                max[i]=max[i-2]+nums[i];
            }
            else{
            max[i]=max[i-3]+nums[i];
            }
        }
        //return the max of the last or second to last element in the array the max depends on if you
        //robbed every 2 or three houses
        if (max[numsSize-1]>max[numsSize-2]){
            return max[numsSize-1];
        }
        else{
            return max[numsSize-2];
            }
        }
        return nums[0];
    }
   
    return 0;
}