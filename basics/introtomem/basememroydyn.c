#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char name[123]; 

    char *dest; 


    strcpy(name, "Lukas");  
    

    dest = malloc(200 * sizeof(char)); 


    strcpy(dest, "Lukas is lukas");

    printf("name is %s and description is %s", name, dest);

}