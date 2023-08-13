#include <stdio.h> 
#include <stdlib.h>
void add_amount(int * num, int add){
    *num += add; 
}

int main(int argc, char ** argv){
    if(argc < 3){
        return 0; 
    }
    int my_value = atoi(argv[1]); 
    printf("My value at first: %i\n", my_value); 

    add_amount(&my_value, atoi(argv[2]));

    printf("My value after: %i\n", my_value); 

    return 0; 


}