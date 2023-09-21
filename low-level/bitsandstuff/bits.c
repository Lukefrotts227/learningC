#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

char * wordShift(char * word, bool isRight, int mag){
    int len = strlen(word); 
    char new_word[len]; 
    if(isRight){
        for(int i = 0; i < len; i++){
            new_word[i] = word[i] >> mag; 
        }
    }else{
        for(int i = 0; i < len; i++){
            new_word[i] = word[i] << mag; 
        }
    }
    return new_word; 
}



int main(){
    char * word; 
    int mag; 
    bool isRight;
    char keepgoing = 'y';

    while(keepgoing == 'y'){
        

    }


    return 0; 
}