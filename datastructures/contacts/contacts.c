#include "contacts.h"
#include <stdio.h> 


char * get_name(){
    char * name; 
    printf("Enter the name: "); 
    scanf("s", name); 
    return name; 
}


long long int get_phonenumber(){
    long long int num; 
    printf("Enter a phone number: "); 
    scanf("%lld", &num); 
    return num; 
}


int main (void){

    unsigned int size; 

    printf("Enter the size: "); 
    scanf("%d", &size); 

    table list = init_table(size); 

    list = table_insert(list, size, get_name(), get_number()); 

    contact * indiv = table_lookup(list, size, get_name()); 

    printf("The number of %s is %lld\n", indiv->name, indiv->number); 

    list = table_insert(list, size, get_name, get_number); 

    list = table_resize(list, size, size + 13); 

    size += 13; 

    indiv = table_lookup(list, size, get_name()); 
    printf("The number of %s is %lld\n", indiv->name, indiv->number); 

    
    list = table_insert(list, size, get_name(), get_number());


    indiv = table_lookup(list, size, get_name());

    printf("The number of %s is %lld\n", indiv->name, indiv->number); 


    

    table_destroy(list, size); 



}











