#include <stdio.h>


float avg(int len, int arr[]);

int main(){

    int nums[4]; 

    nums[0] = 6;
    nums[1] = 6;   
    nums[2] = 4;
    nums[3] = 12;

    float average = avg(4, nums);

    printf("The average is %f\n", average);

    return 0; 
}


float avg(int len, int arr[]){

    int sum = 0; 

    for(int i = 0; i < len; i = i + 1){

        sum = sum + arr[i]; 


    }

    return sum /  (float) len;
}