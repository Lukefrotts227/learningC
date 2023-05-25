#include <stdio.h>
#include <string.h>

union something{

    int num; 

    float number; 

    char word[33];
}; 


int main(){

    union something some; 


    some.num = 323; 
    some.number = 314.324; 

    strcpy(some.word, "Bobby"); 


    printf("%s\n%i\n%f",some.word, some.num, some.number);


    return 0; 



}