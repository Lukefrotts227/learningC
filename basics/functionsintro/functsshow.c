#include <stdio.h>
#include <stdbool.h>


int max(int num1, int num2); 
bool boolmax(int num1, int num2);

int main(){

    int x; 
    int y; 

    printf("Enter the first number: "); 
    scanf("%i", &x);

    printf("Enter the second number: ");
    scanf("%i", &x);


    int ret1 = max(x,y);
    bool ret2 = boolmax(x,y);

    printf("%i and is %s", ret1, ret2 ? "false" : "true");  

    return 0; 
}


int max(int num1, int num2){

    int res; 

    if(num1 > num2){
        res = num1; 
    }

    else{
        res = num2;
    }
    return res; 
}

bool boolmax(int num1, int num2){
    bool res; 

    if(num1 > num2){
        res = true; 
     }

    else{
        res = false;
    }
    return res; 
}
