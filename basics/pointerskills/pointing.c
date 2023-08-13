#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char * argv){
    int * point = malloc(sizeof(int)); 
    *point = 423; 
    printf("%i", *point); 

    free(point);
    return 0; 
}