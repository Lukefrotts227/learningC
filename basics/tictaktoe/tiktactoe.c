#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


char* getBoard(char arr[3][3]);
bool canInsert(char arr[3][3], int choiceR, int choiceC); 
int winCond(char arr[3][3]);


int main(){ 
    bool gameGoing = true; 
    bool subGameGoing = true; 
    int row; 
    int collumn; 
    int gameOutcome; 

    printf("Welcome to the tictactoe game.\n"); 
    
    char myArray[3][3] = {
        {'n', 'n', 'n'},
        {'n', 'n', 'n'},
        {'n', 'n', 'n'}
    }; 
    char* myRet = getBoard(myArray);

    
    /* 
    char* myRet = getBoard(myArray); 

    printf("%i\n", winCond(myArray)); 

    printf("%s\n", myRet); 
    //free(myRet); 

    printf("%s\n", canInsert(myArray, 2, 2) ? "true" : "false"); 

    printf("%s\n", canInsert(myArray, -1, 3) ? "true" : "false"); 
    printf("%s\n", canInsert(myArray, 1, 4) ? "true" : "false"); 
    printf("%c\n", myArray[0][1]);
    printf("%s\n", canInsert(myArray, 0, 1) ? "true" : "false"); 
    */


   // Game loop 

   while(gameGoing == true){
    // player 1
        printf("player 1 turn now \n");

        while(subGameGoing == true){

            printf("%s\n", myRet);

            printf("Enter your row choice here: ");
            scanf("%i", row); 

            printf("Enter your collumn choice here: "); 
            scanf("%i", collumn); 

            row = row -1; 
            collumn = collumn -1; 

            if(canInsert(myArray, row, collumn) == true){
                subGameGoing = false;
            }
        }

        gameOutcome = winCond(myArray); 
        if(gameOutcome != 0){
            break;
        }

        // player 2 
        printf("player 2 turn now \n");

        while(subGameGoing == true){

            printf("%s\n", myRet);

            printf("Enter your row choice here: ");
            scanf("%i", row); 

            printf("Enter your collumn choice here: "); 
            scanf("%i", collumn); 

            row = row -1; 
            collumn = collumn -1; 

            if(canInsert(myArray, row, collumn) == true){
                subGameGoing = false;
            }
        }
        gameOutcome = winCond(myArray); 
        if(gameOutcome != 0) {
            gameGoing = false; 
        }   


   }

   if (gameOutcome == 1){
    printf("player 1 wins!");
   }
   else if (gameOutcome == 2){
    printf("player 2 wins!"); 
   }
   else{
    printf("tie game"); 
   }





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
    bool tyinggame = false; 
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){
            if (arr[i][j] == 'n'){
                tieGame = false; 
                tyinggame = true;
                printf("passed");
                break;
            }
            else {
                tieGame = true; 
            }
        
        }
        if(tyinggame == true){
            break;
        }

    }
    if (tieGame = true && tyinggame == false){
        return 3; 
    }

    // player 1 is X
    // player 2 is O

    // check if player 1 has won


    // check at first pos 

    if(arr[0][0] == 'X'){

        if(arr[1][1] == 'X'){
            if(arr[2][2] == 'X'){
                return 1;
            }
        }

        if(arr[0][1] == 'X'){
            if(arr[0][2] == 'X'){
                return 1; 
            }
        }
        if(arr[1][0]){
            if(arr[2][0] == 'X'){
                return 1;
            }
        }

    }

    if(arr[0][1] == 'X'){
        if(arr[1][1] == 'X'){
            if(arr[2][1] == 'X'){
                return 1; 
            }
        }
    }

    if(arr[0][2] == 'X'){
        if(arr[1][1] == true){
            if(arr[2][0] == 'X'){
                return 1;
            }
        }

        if(arr[1][2] == 'X'){
            if(arr[2][2] == 'X'){
                return 1; 
            }
        }
    }

    if(arr[1][0] == 'X'){
        if(arr[1][1] == 'X'){
            if(arr[1][2] == 'X'){
                return 1;
            }
        }

    }

    if(arr[2][0 == 'X']){
        if(arr[2][1] == 'X'){
            if(arr[2][2] == 'X'){
                return 1; 
            }
        }

    }




    if(arr[0][0] == 'O'){

        if(arr[1][1] == 'O'){
            if(arr[2][2] == 'O'){
                return 2;
            }
        }

        if(arr[0][1] == 'O'){
            if(arr[0][2] == 'O'){
                return 2; 
            }
        }
        if(arr[1][0]){
            if(arr[2][0] == 'O'){
                return 2;
            }
        }

    }

    if(arr[0][1] == 'O'){
        if(arr[1][1] == 'O'){
            if(arr[2][1] == 'O'){
                return 2; 
            }
        }
    }

    if(arr[0][2] == 'O'){
        if(arr[1][1] == true){
            if(arr[2][0] == 'O'){
                return 2;
            }
        }

        if(arr[1][2] == 'O'){
            if(arr[2][2] == 'O'){
                return 2; 
            }
        }
    }

    if(arr[1][0] == 'O'){
        if(arr[1][1] == 'O'){
            if(arr[1][2] == 'O'){
                return 2;
            }
        }

    }

    if(arr[2][0 == 'O']){
        if(arr[2][1] == 'O'){
            if(arr[2][2] == 'O'){
                return 2; 
            }
        }

    }
    return 0;
    
}





