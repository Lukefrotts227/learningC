#include <stdio.h>

int main(){
    int i; 
    int choice; 

    for(i = 0; i < 5; i = i + 1){
        printf("Enter 0 if you want to skip and anything else if you do not: ");

        scanf("%i", &choice); 

        if(choice == 0){
            continue; 
        }

        // continue test
        printf("we printing this!!!\n");
    }
    return 0;
}