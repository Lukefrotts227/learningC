#include <stdio.h> 
#include <stdlib.h>


char* getBoard(char arr[3][3]);

int main(){ 
    printf("Welcome to the tictactoe game.\n"); 
    
    char myArray[3][3] = {
        {'n', 'n', 'n'},
        {'n', 'n', 'n'},
        {'n', 'n', 'n'}
    }; 
    





    
    





    return 0; 
}



char* getBoard(char arr[3][3]){

    char* res = malloc(sizeof(arr) + 6 ); 

    int ind = 0; 
    for (int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){
            res[ind] = arr[i][j]; 
            ind++; 

            res[ind] = ' '; 

        }

    }


}

