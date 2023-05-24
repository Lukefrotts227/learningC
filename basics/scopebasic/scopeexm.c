#include <stdio.h>

int glob; 

int main(){
    int numfour = 4; 
    int x; 

    printf("Enter the number you want to add 4 too: ");

    scanf("%i", &x); 

    glob = x + numfour; 

    printf("The number is %i", glob); 

    return 0; 
}