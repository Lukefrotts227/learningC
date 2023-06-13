#include <stdio.h> 


#define SquareArea(s) (s*s)

int main(){
    float side_length; 

    printf("Enter the side length of the square: ");
    scanf("%f", &side_length); 

    float area = SquareArea(side_length); 
    printf("the area is %.2f", area); 

    return 0; 
}