#include <stdio.h> 


int main(){
    int size; 

    printf("Enter the size of the shape: "); 

    scanf("%i", &size); 

    int i; 
    int j; 

    for(i = 0; i < size; i = i + 1){

        for(j = 0; j < i; j = j += 1){
            printf("#");
        }
        printf("\n"); 

    }

    return 0;
}