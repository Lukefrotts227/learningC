#include <stdio.h>
#include <stdlib.h>

// A basic "memory" file that writes information to a given file
// includes the ability to clear that file
// includes the ability to print out what is on the file
// includes the ability to write new information to the file

int main(){
    FILE *myFile; 

    myFile = fopen("fileofme.txt", "w+"); 

    if(myFile == NULL){
        printf("Could not open the file!!\n"); 
       
        return 1; 
    }




    return 0; 


}