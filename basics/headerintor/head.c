#include <stdio.h>
#include <myhead.h>

int main(){
    int choice; 
    int num1; 
    int num2; 
    int tot; 

    printf("Choose 1 to multiply and 0 to add: "); 
    scanf("%i", &choice); 

    if (choice == 0){
        printf("Enter the first number: "); 
        scanf("%i", &num1); 
        printf("Now enter the second one: "); 
        scanf("%i", &num2); 
        tot = num1 + num2; 

        printf("The sum of them is: %i", tot); 

    }

    else if (choice == 1){

    }
    else{
        printf("invalid choice!!!");
    }

    

    return 0; 
}