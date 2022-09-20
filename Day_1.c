#include<stdio.h>  
#include<stdint.h>
#include<string.h>

//Day 1
int countOdds(int low, int high){
    int diff = high-low;
    
    int oddcount = diff/2;
    if(low%2 != 0 || high%2 != 0){
        oddcount++;
    }
    return oddcount;
}

double average(int* salary, int salarySize){
    int highest=salary[0], lowest=salary[0];
    double salarycounter=0;
    for(int i = 0; i < salarySize; i++){
        if(salary[i]<lowest){
            lowest = salary[i];
        }
        else if(salary[i]>highest){
            highest = salary[i];
        }
    }
    
    for(int i = 0; i < salarySize; i++){
        if (salary[i] != lowest && salary[i] != highest)
        {
            salarycounter += salary[i];
        }
    
    }
    
    return salarycounter/(salarySize-2);
}


int main()  
{  
    int salary[] = {4000,3000,2000,1000};
    printf("Number of odd numbers inbetween: %d\n",countOdds(3, 7));
    printf("Average salary excluding min and max: %d",average(salary, 4));
   
}  
