#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
// take input either from user or as cmd line input
// ./main 010101 d
// ./main 123 b

int checkIfBin(const char * binary){
    int len = strlen(binary); 
    for(int i = 0; i < len; i++){
        if(binary[i] != '0' && binary[i] != '1'){
            return 1; 
        }
    }
    return 0; 
}


int binaryToDecimal(const char * binary){
    int decimal = 0; 
    int len = strlen(binary); 

    for (int i = 0; i < len; i++){
        if (binary[len - 1 - i] == '1'){
            int pow = 1; 
            for (int j = 0; j < i; j++){
                pow*=2; 
            }
            decimal+=pow;
        }
       
    }

    return decimal; 
}

char * decimalToBinary(int decimal){
    char binary[100]; 
    int ind = 0; 

    if(decimal == 0){
        binary[0] = '0'; 
        binary[1] = '\0';
    }else{
        while(decimal > 0){
            binary[ind++] = (decimal % 2) + '0'; 
            decimal /=2; 
        }
        binary[ind] = '\0'; 
        for(int i = 0; i < ind/2; i++){
            char temp = binary[i]; 
            binary[i] = binary[ind-1-i]; 
            binary[ind-1-i] = temp; 
        }

    }
    char * res = (char *)malloc(strlen(binary) + 1); 
    strcpy(res, binary); 
    return res; 

}



int main(int argc, char * argv){
    if(argc == 1){

    }else if(argc == 3){
        char type = argv[2]; 
        if(type == 'b'){
            // do the conversion

        }else if(type == 'd'){
            if(checkIfBin(argv[1]) == 1){
                printf("Must be valid binary!!\n"); 
                return 1; 
            }
            // do the conversion
        }
        printf("must be b or d conversion!\n"); 
        return 1; 

    }

    printf("invalid command line args!!\n"); 
    return 1; 
    
}



