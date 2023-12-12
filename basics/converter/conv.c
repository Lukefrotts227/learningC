#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
/* 
take input either from user or as cmd line input
./main 010101 d
./main 123 b
if the program returns 1 then there was an error
 */

// check if valid binary
int checkIfBin(const char * binary){
    int len = strlen(binary); 
    for(int i = 0; i < len; i++){
        if(binary[i] != '0' && binary[i] != '1'){
            return 1; 
        }
    }
    return 0; 
}

// convert binary to decimal returns as int
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

// converts decimal to binary return as char *(string)
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


// main function
int main(int argc, char *argv[]) {
    // if the user does not provide any command line arguemnts
    if (argc == 1) {
        char input[100];
        printf("Enter a number: ");
        scanf("%s", input);
        printf("Enter b for binary or d for decimal: ");
        char type;
        scanf(" %c", &type);
        if (type == 'b') {
            int decimal = atoi(input);
            char *binary = decimalToBinary(decimal);
            printf("Decimal %d to Binary: %s\n", decimal, binary);
            free(binary);
        } else if (type == 'd') {
            if (checkIfBin(input)) {
                printf("Must be valid binary!\n");
                return 1;
            }
            int decimal = binaryToDecimal(input);
            printf("Binary %s to Decimal: %d\n", input, decimal);
        } else {
            printf("Must specify b for binary or d for decimal conversion!\n");
            return 1;
        }
        return 0;
    }
    if (argc != 3) {
        printf("Usage: ./program <number> <b/d>\n or ./program\n");
        return 1;
    }

    char type = argv[2][0];
    if (type == 'b') {
        int decimal = atoi(argv[1]);
        char *binary = decimalToBinary(decimal);
        printf("Decimal %d to Binary: %s\n", decimal, binary);
        free(binary);
    } else if (type == 'd') {
        if (checkIfBin(argv[1])) {
            printf("Must be valid binary!\n");
            return 1;
        }
        int decimal = binaryToDecimal(argv[1]);
        printf("Binary %s to Decimal: %d\n", argv[1], decimal);
    } else {
        printf("Must specify b for binary or d for decimal conversion!\n");
        return 1;
    }

    return 0;
}

