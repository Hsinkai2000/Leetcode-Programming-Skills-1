#include<stdio.h>  
#include<stdint.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>
//Day 4


// There is a function signFunc(x) that returns:

// 1) 1 if x is positive.
// 2) -1 if x is negative.
// 3) 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).
//method 1
int signFunc(int product){
    if (product == 0)
    {
        return 0;
    }
    else if (product < 1)
    {
        return -1;
    }
    else{
        return 1;
    }  
}

int arraySign(int* nums, int numsSize){
    //set product as nums 0
    int product = nums[0];
    //loop through nums and find product of all of the items in array
    for(int i = 1; i < numsSize; i++){
        product *= nums[i];
    }
    //return based on conditions stated
    return signFunc(product);
}

//method 2
int signFunc2(int x){
    if (x=0)
    {
        return 0;
    }
    
    if (x%2 == 0)
    {
        return 1;
    }
    else if (x%2 == 1)
    {
        return -1;
    }
}

int arraySign2(int* nums, int numsSize){
    //set a counter as 2 so it does not automatically become product == 0 when there is 1 item
    int counter = 2;
    //loop through nums and find out how many negative numbers are there
    for(int i = 0; i < numsSize; i++){
        //if there is a 0, whole product will be 0
        if (nums[i] == 0)
        {
            counter = 0;
            break;
        }
        if (nums[i] < 0)
        {
            counter++;
        }        
    }

    return signFunc2(counter);
}

// A sequence of numbers is called an arithmetic progression if the difference between any two 
//consecutive elements is the same.

// Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic 
//progression. Otherwise, return false.
int cmp(const void *a, const void *b){
     return *(int*)a > *(int*)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    //sort from smallest to biggest. difference in sequence only can be up to biggest difference
    // qsort(arr, arrSize, sizeof(int), cmp);    
    int maxDiff = ceil((arr[arrSize-1]-arr[0])/(arrSize-1));
    bool check = true;
    for (int i = 0; i < arrSize-1; i++)
    {
        printf("asd : %d", arr[i]);
        if(arr[i] + maxDiff != arr[i+1]){
          check = false;
        }
    }
    return check;
}

// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose 
// two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on 
// exactly one of the strings. Otherwise, return false.

bool areAlmostEqual(char * s1, char * s2){
      char a, b;
    int diff = 0;
	// strings are equal so we go until we reach
    while (*s1 != '\0') {
	// if strings not equal remember the char
	// from each string current position
        if (*s1 != *s2) {
			// encounter difference second time
            if (diff) {
                if (a != *s2 || b != *s1)
                    return false;
            }
			// encounter difference first time
            if (!diff) {
               a = *s1;
               b = *s2;
            }
            diff++;
            if (diff > 2) return false;
        }
        s1++;
        s2++;
    }
    if (diff == 0) return true;
    if (diff == 1) return false;
    return true;
    
}

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

int sumSquares(int n){
    int sum = 0,digit;
    if (n == 1 || n == 4)
    {
       return n;
    }
    else{
        while (n>0)
        {
            printf("entered here");
            //find digit i
            digit = n%10;
            //add squared of digit i
            sum += pow(digit,2);
            //prepare to find digit 2
            n= n/10;
        }
        return sumSquares(sum);
    }
}

int isHappy(int n){
    int sum = sumSquares(n);    
    //if n ends at 1 return true
    if (sum == 1)
    {
        return 1;
    }
    //all non happy ends at 4. if n ends at 4 return false
    else if (sum == 4)
    {
        return 0;
    }    
    else{
        return 0;
    }
}

void main(){
    printf("%d",isHappy(2));
}