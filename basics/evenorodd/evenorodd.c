#include <stdio.h>


int main(){
    int number; 
    printf("Enter a whole number: "); 
    scanf("%i", &number); 

    if(number % 2 == 0)
    {
        printf("even number");
    }
    else 
    {
        printf("odd number");    
    }

    return 0;
}