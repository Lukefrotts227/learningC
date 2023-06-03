#include <stdio.h>

int main(){
    int starter; 

    printf("Please choose a starter value :) "); 

    scanf("%i", &starter);

    int i; 

    for(i = starter; i < starter + 11; i = i + 1){
        printf("The value is: %i\n", i);
    }


    return 0;
}