#include "contacts.h"
#include <stdio.h> 


int main (void){

    unsigned int size; 

    printf("Enter the size: "); 
    scanf("%d", &size); 

    table list = init_table(size); 

    list = table_insert(list, size, "Bobby Mitch", 9732348791LL); 

    contact * indiv = table_lookup(list, size, "Bobby Mitch"); 

    printf("The number of %s is %lld\n", indiv->name, indiv->number); 

    list = table_insert(list, size, "Bobby Johnson", 8642314456LL); 

    list = table_resize(list, size, size + 13); 

    size += 13; 

    indiv = table_lookup(list, size, "Bobby Johnson"); 
    printf("The number of %s is %lld\n", indiv->name, indiv->number); 

    
    list = table_insert(list, size, "Bobby Mitch", 9832348791LL);


    indiv = table_lookup(list, size, "Bobby Mitch");

    printf("The number of %s is %lld\n", indiv->name, indiv->number); 


    


    

    table_destroy(list, size); 



}











