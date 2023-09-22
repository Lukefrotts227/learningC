#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

char * wordShift(const char * word, bool isRight, int mag){
    int len = strlen(word); 
    char* new_word = (char*)malloc(len + 1);

    if (new_word == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }


    if(isRight){
        for(int i = 0; i < len; i++){
            new_word[i] = word[i] >> mag; 
        }
    }else{
        for(int i = 0; i < len; i++){
            new_word[i] = word[i] << mag; 
        }
    }
    new_word[len] = '\0'; // Null-terminate the new string
    return new_word; 
}



int main(){
    char * shiftedWord; 
    char word[100]; 
    int mag; 
    int isRight;
    char keepgoing = 'y';

    while(keepgoing == 'y'){
        printf("Enter a string: "); 
        scanf("%s", word); 

        getchar(); 

        printf("Enter 0 to go right. And other to go left: ");
        scanf("%i", &isRight); 


        printf("Enter the magnitude of the shift: "); 
        scanf("%i", &mag); 

        getchar();



        if(isRight == 0){
            shiftedWord = wordShift(word, true, mag); 
            printf("%s shifted is %s", word, shiftedWord); 
        }else {
            shiftedWord = wordShift(word, true, mag); 
            printf("%s shifted is %s", word, shiftedWord); 

        }
        free(shiftedWord); 
        printf("Do you wish to continue (y/n): "); 
        scanf("%c", &keepgoing); 
        

    }


    return 0; 
}