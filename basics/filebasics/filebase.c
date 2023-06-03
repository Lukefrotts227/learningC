#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp; 

    fp = fopen("tester.txt", "w+");

    fprintf(fp, "here we go I guess"); 

    fclose(fp); 
    return 0; 


}