#include <stdio.h>

int main(){
    int size1, size2;
    
    int i, j; 
    int builder; 

    printf("Enter the size of the over array: "); 
    scanf("%i", &size1); 

    printf("Enter the size of the under arrays: "); 
    scanf("%i", &size2); 

    int arr[size1][size2]; 



    // build the array
    for(i = 0; i < size1; i++){

        for (j = 0; j < size2; j++){
            printf("Enter the %ith element of the %ith array: ",j, i); 

            scanf("%i", &builder); 

            arr[i][j] = builder;
        }
    }

    // print the array
    for(i = 0; i < size1; i++){

        for(j = 0; j < size2; j++){

            printf("The %ith element of the %ith array is %i\n", j, i, arr[i][j]); 
        }
    }

    return 0; 
}