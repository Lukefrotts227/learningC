#include "contacts.h"
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

char * to_lowercase(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]); 
    }
    return str; 
}

int make_choice(char * str){
    return 0; 
}


char * get_name(){
    char * name; 
    printf("Enter the name: "); 
    scanf("%s", name); 
    
    return name; 
}


long long int get_phonenumber(){
    long long int num; 
    printf("Enter a phone number: "); 
    scanf("%lld", &num); 
    
    return num; 
}

contact * uni_lookup(table list, unsigned int size, const char * name){
    contact * test = table_lookup(list, size, name); 

    if (test != NULL){
        return test; 
    }

    int ind = findInCache(list, name); 

    if (ind == -1){
        return NULL;
    }

    return list.extras[ind]; 
}

table load_from_file( unsigned int size, char * file_name){

    table cont = init_table(size); 

    FILE * file_p; 
    file_p = fopen(file_name, "r"); 
    if(file_p == NULL){
        fprintf(stderr, "file did not open\nExiting progam\n"); 

        exit(0); 
    }

    char first_name[255]; 
    char last_name[255];
    char name[256]; 
    long long int number; 

    while(fscanf(file_p, "%s %s %lld", first_name, last_name, &number) == 2){
        strcpy(name, first_name); 
        strcat(name, " "); 
        strcat(name, last_name); 

        table_insert(cont, size, name, number); 
    }

    fclose(file_p); 

    return cont; 

}

void load_to_file(table cont, unsigned int size, char * file_name){

    FILE * file_p; 

    file_p = fopen(file_name, 'w'); 

    if(file_p == NULL){

        fprintf(stderr, "file did not open\nExiting program\n"); 

        exit(0); 
    }

    for(int i = 0; i < size; i++){
        if(cont.contacts[i] != NULL){
            fprintf(file_p, "%s %lld\n", cont.contacts[i]->name, cont.contacts[i]->number);
        }
    }

    for(int i = 0; i < cont.cache_size; i++) {
        fprintf(file_p, "%s %lld\n",cont.extras[i]->name, cont.extras[i]->number); 
    }


    table_destroy(cont, size); 

}


int main (void){

    unsigned int size; 

    printf("Enter the size: "); 
    scanf("%d", &size); 

   

    




}











