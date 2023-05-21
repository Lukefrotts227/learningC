#include <stdio.h>


int main(){
    int age; 
    char name[22]; 
    printf("Enter your name please: "); // ask for the name
    scanf("%21s", name); // get the name
    printf("Enter your age please: "); // ask the age
    scanf("%i", &age); // get the age

    printf("your name is %s and your age is %i", name, age); 

    return 0;


}