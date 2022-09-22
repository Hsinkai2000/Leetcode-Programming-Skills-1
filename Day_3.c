#include<stdio.h>  
#include<stdint.h>
#include<string.h>
#include<math.h>
#define INT_MAX 999999999

//Given an integer array nums, return the largest perimeter of a triangle 
//with a non-zero area, formed from three of these lengths. 
//If it is impossible to form any triangle of a non-zero area, return 0.

int cmp(const void *a, const void *b){
    return *(int*)a < *(int*)b;
}

int largestPerimeter(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int i;
    for(i = 0; i < numsSize - 2; i++){
        // Concept: Because nums is sorted from largest to smallest, if nums[i] > nums[i + 1] + nums[i + 2], any other combination of 
		// nums[i + j] + nums[i + k] after nums[i + 1] + nums[i + 2] is not possible to make nums[i] < nums[i + j] + nums[i + k]. 
        // Therefore, including nums[i] does not make a valid triangle. We try the next element. 
        if(nums[i] < nums[i + 1] + nums[i + 2])
            return nums[i] + nums[i + 1] + nums[i + 2];
    }
    
    return 0;
}

// You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). 
//You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). 
//A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

// Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. 
//If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.

// The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).



int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){
    int index=-1;        
    int shortestdist=INT_MAX;//set shortest dist as max integer
    for(int i=0;i<pointsSize;i++){
        if(x==points[i][0] || y==points[i][1]){            //check if point is valid    
            int dist=abs(x-points[i][0])+abs(y-points[i][1]);        //if valid, calculate distance        
            if(dist<shortestdist ){  //check if distance shorter than shortest dist. wont be true if repeated dist
                index=i;                                  
                shortestdist=dist;                    
            }                
        }            
    }    
    return index;    
}


int main()  
{  
    // printf("The largest perimeter is: %d\n",largestPerimeter(num, 3));
    // printf("Average salary excluding min and max: %d",nearestValidPoint(3, 4, pos, 3, 2));
   
}  