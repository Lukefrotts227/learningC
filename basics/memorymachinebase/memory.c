#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

// A basic "memory" file that writes information to a given file
// includes the ability to clear that file
// includes the ability to print out what is on the file
// includes the ability to write new information to the file

int main(){
    FILE *myFile; 
    bool keepgoing = true; 
    int choice; 
    char info[231]; 
    char ch; 



    while(keepgoing == true){

        printf("Enter 0 to write info to the file.\n"); 
        printf("Enter 1 to print out what is on the file.\n"); 
        printf("Enter 2 to clear the file.\n");
        printf("Enter 3 to exit the loop.\n"); 

        printf("Enter you choice here: "); 

        scanf("%i", &choice); 
        getchar(); 

        if(choice == 0){
            myFile = fopen("fileofme.txt", "a"); 

            if(myFile == NULL){
                printf("Could not open the file!!\n"); 
       
                return 1; 
            }
            printf("Enter what you wish to add to the file here: ");
            fgets(info, sizeof(info), stdin); 
            fprintf(myFile, info); 
            fclose(myFile); 


        }

        else if(choice == 1){
            myFile = fopen("fileofme.txt", "r"); 

            if(myFile == NULL){
                printf("Could not open the file!!\n"); 
       
                return 1; 
            }
            
            do {
                ch = fgetc(myFile); 
                printf("%c", ch); 
            } while(ch != EOF); 
            fclose(myFile);


        }

        else if(choice == 2){
            fclose(fopen("fileofme.txt", "w"));

        }

        else if(choice == 3){

            printf("sounds good !\n"); 
            keepgoing = false; 
        }
        else{
            printf("INVALID CHOICE...\nPlease try again\n"); 
        }






    }

    //fclose(myFile);



    return 0; 


}



