#include<stdio.h>  
#include<stdint.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. 
// Each group of children is separated by the null value (See examples)
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void search(struct Node* root, int* arr, int* idx) {
    if (!root) return;
    arr[(*idx)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        search(root->children[i], arr, idx);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int* arr = (int*) malloc(10000 * sizeof(int));
    int idx = 0;
    search(root, arr, &idx);
    *returnSize = idx;
    return arr;
}

// The next greater element of some element x in an array is the first greater 
// element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 
// is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and 
// determine the next greater element of nums2[j] in nums2. If there is no next greater
// element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element
//  as described above.

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    int * res = (int *)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;
    
    int hash[10001]={0};
    int v,k=0;
    int i;
    //set all value in res as no bigger number
    for (i=0; i < nums1Size; i++)
    {
        res[i]=-1;
    }
    //place values in nums2 into a hash
    for (i=0; i < nums2Size; i++)
    {
        v = nums2[i];
        hash[v] = i;
    }
    //loop through nums1
    for (i=0; i < nums1Size; i++)
    {
        //set values in nums1 into hash
        v = nums1[i];
        v = hash[v];
        while (v < nums2Size)
        {
            if (nums2[v] > nums1[i])
            {
                res[k] = nums2[v];
                break;
            }
            v++;
        }
        k++;
        
    }    
    return &res[0];

}

// You are given an array coordinates, coordinates[i] = [x, y], 
// where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    //straight line == same gradient == dy1/dx1 = dy2/dx2

    //find dx1,dx2,dy1,dy2
    int dx1 = coordinates[0][0] - coordinates[1][0];
    int dy1 = coordinates[0][1] - coordinates[1][1];
    int dx2, dy2;
    //from coordinates 3 onwards, find the gradient
    for(int i = 2; i < coordinatesSize; i++)
    {
        dx2 = coordinates[i][0] - coordinates[i-1][0];
        dy2 = coordinates[i][1] - coordinates[i-1][1];
        //return false if gradient is different at any point
        if(dx2*dy1 != dx1*dy2){
           return false;
        } 
    }
    return true;

}

void main(){

}