#include <stdio.h>

int main(){
    int i; 
    int howLong; 

    printf("enter the number of how long you want to go: "); 
    scanf("%i", &howLong); 

    for(i = 0; i < howLong; i = i + 1){

        if(i % 5 == 0){
            printf("We don't print multiples of 5!!!!\n");
        }
        else{
            printf("the number: %i\n", i); 
        }
    }

    return 0; 
}