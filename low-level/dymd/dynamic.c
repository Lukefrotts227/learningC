#include <stdio.h> 
#include <stdlib.h> 
int ***** big_boy_builder(unsigned int init_size){
    int ***** fived = malloc(sizeof(int *****) * init_size);
    for(int i = 0; i < init_size; i++){
        fived[i] = malloc(sizeof(int ****) * init_size);
        for(int j = 0; j < init_size; j++){
            fived[j] = malloc(sizeof(int ***) * init_size);
            for(int k = 0; k < init_size; k++){
                fived[k] = malloc(sizeof(int **) * init_size);
                for(int l = 0; l < init_size; l++){
                    fived[l] = malloc(sizeof(int *) * init_size);
                    for(int m = 0; m < init_size; m++){
                        fived[m] = malloc(sizeof(int) * init_size);
                    }
                }
            }
        }
    }
    return fived; 

}

void big_boy_destroy(int ***** fived, unsigned int init_size){
    for(int i = 0; i < init_size; i++){
        for(int j = 0; j < init_size; j++){
            for(int k = 0; k < init_size; k++){
                for(int l = 0; l < init_size; l++){
                    for(int m = 0; m < init_size; m++){
                        free(fived[i][j][k][l][m]);
                    }
                    free(fived[i][j][k][l]);
                }
                free(fived[i][j][k]);
            }
            free(fived[i][j]);
        }
        free(fived[i]);
    }
    free(fived);
}


int main(void){

}

