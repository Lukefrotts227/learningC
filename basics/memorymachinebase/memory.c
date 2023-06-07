#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

// A basic "memory" file that writes information to a given file
// includes the ability to clear that file
// includes the ability to print out what is on the file
// includes the ability to write new information to the file

int main(){
    FILE *myFile; 
    bool keepgoing = true; 

    myFile = fopen("fileofme.txt", "w+"); 

    if(myFile == NULL){
        printf("Could not open the file!!\n"); 
       
        return 1; 
    }

    while(keepgoing == true){

        
    }



    return 0; 


}