#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


char* getBoard(char arr[3][3]);
bool canInsert(char arr[3][3], int choiceR, int choiceC); 
int winCond(char arr[3][3]);


int main(){ 
    bool gameGoing = true; 

    printf("Welcome to the tictactoe game.\n"); 
    
    char myArray[3][3] = {
        {'n', 'X', 'n'},
        {'n', 'n', 'n'},
        {'n', 'n', 'n'}
    }; 
    

    char* myRet = getBoard(myArray); 



    /*
    printf("%s\n", myRet); 
    //free(myRet); 

    printf("%s\n", canInsert(myArray, 2, 2) ? "true" : "false"); 

    printf("%s\n", canInsert(myArray, -1, 3) ? "true" : "false"); 
    printf("%s\n", canInsert(myArray, 1, 4) ? "true" : "false"); 
    printf("%c\n", myArray[0][1]);
    printf("%s\n", canInsert(myArray, 0, 1) ? "true" : "false"); 
    */





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

    if(arr[choiceR][choiceC] != 'n'){
        answer = false; 
    }
    else if(choiceR >= 3 || choiceC >= 3 || choiceR < 0 || choiceC < 0 ){
        answer = false;
    }
    else{
        answer = true; 
    }


    return answer; 

}



// 0 is game continue
// 1 is player 1 wins 
// 2 is player three wins
// 3 is tie game 

int winCond(char arr[3][3]){

    // tie game logic
    
    bool tieGame = false; 
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){
            
        }

    }



    
}



