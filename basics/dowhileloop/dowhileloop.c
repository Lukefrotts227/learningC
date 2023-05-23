#include <stdio.h>

int main(){
    int x = 0; 

    do{
        printf("%i\n", x); 
        x = x + 1;
    } while(x<8);

    return 0;
}