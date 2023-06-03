#include <stdio.h>

int sum(int n); 

int main(){
    int num;
    printf("Enter a number to apply the sum function to: "); 
    scanf("%i", &num); 
    int result = sum(num);
    printf("The sum of all numbers is: %i", result);
}


int sum(int n){

    if(n > 0){
        return n + sum(n-1); 

    }
    else{
        return 0; 
    }
    
}