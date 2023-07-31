#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


#define MAX_SIZE 256

char ** init_array(unsigned int size){

    char ** arr = malloc(size * sizeof(char[MAX_SIZE])); 

    if (arr == NULL){
        fprintf(stderr, "Memory alloaction error"); 
        return NULL; 
    }

    return arr; 
}


char ** insert_string(char ** arr, char * str, unsigned int place){

    int len = strlen(str); 

    for(int i = 0; i < len; i++){
        arr[place][i] = str[i];
    }
    return arr; 

}

char * grab_string(char ** arr, unsigned int place){
    char * str = arr[place]; 

    return str; 

}

char ** resize_array(char ** arr, unsigned int size, unsigned int new_size){

    char **  new_array = init_array(new_size); 

    for(int i = 0; i < new_size; i++){

        if(!(i > size)){
            insert_string(new_array, arr[i], i); 
        }
    }



    for (unsigned int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return new_array;  
    

}


int main(void){
    unsigned int size; 

    printf("Enter the size: "); 
    scanf("%i", &size); 




    return 0; 
}
