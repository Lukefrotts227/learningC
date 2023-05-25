#include <stdio.h>


int main(){


    int var = 2143; 

    int *varpnt; 


    varpnt = &var; 

    printf("Watch me access the variable using the pointer \n here we go...\n this is it: %i", *varpnt); 

    




    return 0; 
}