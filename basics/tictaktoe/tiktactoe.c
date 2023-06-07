#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


char* getBoard(char arr[3][3]);
bool canInsert(char arr[3][3], int choiceR, int choiceC); 

int main(){ 
    printf("Welcome to the tictactoe game.\n"); 
    
    char myArray[3][3] = {
        {'n', 'n', 'n'},
        {'n', 'n', 'n'},
        {'n', 'n', 'n'}
    }; 
    

    char* myRet = getBoard(myArray); 




    printf("%s\n", myRet); 
    //free(myRet); 



    
    





    return 0; 
}



char* getBoard(char arr[3][3]){
    //int totalsize = (size*size) + (size-1) + size; 
    //char* res = malloc( 6 + sizeof(arr)); 
    //char res[9];
    char* res = malloc(9); 

    int ind = 0; 
    for (int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){
            res[ind] = arr[i][j]; 
            ind++; 

            res[ind] = ' '; 
            ind++; 

        }
        res[ind] = '\n'; 
        ind++; 

    }
    res[ind-1] = '\0'; 

    return res; 


}



bool canInsert(char arr[3][3], int choiceR, int choiceC){
    bool answer; 


    return answer; 

}

