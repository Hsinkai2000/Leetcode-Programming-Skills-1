#include<stdio.h>  
#include<stdint.h>
#include<string.h>


//Day 2
int hammingWeight(uint32_t n) {
    int counter = 0;
    while(n){
        n = n & (n-1);
        counter++;
    }
    return counter;
}

int subtractProductAndSum(int n){
    int sum = 0,product = 1;
    //iterate through digits
    while (n!=0){
        int right_digit = n%10;
        sum += right_digit;
        product *= right_digit;
        n /= 10; //remove last digit
    }
    return (product - sum);
}

int main()
{
    printf("Number of 1s in the bitcode: %d\n",hammingWeight(00000011101));
    printf("Difference between the product and sum of individual digits: %d\n",subtractProductAndSum(4421));
    return 0;
}