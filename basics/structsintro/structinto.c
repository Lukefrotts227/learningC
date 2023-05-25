#include <stdio.h> 
#include <string.h>

struct Student { 
    char name[33]; 

    int age; 

    float gpa; 
}; 


int main(){
    char nme[33]; 

    int ag; 

    float gp; 

    struct Student std1; 

    printf("Enter the student name: "); 

    scanf("%s", &nme);

    strcpy( std1.name, nme); 


    printf("Enter the student age: "); 

    scanf("%i", &ag); 

    std1.age = ag; 

    
    printf("Enter the student gpa: "); 
    
    scanf("%f", &gp); 

    std1.gpa = gp; 


    printf("%s is %i years old and has a %f gpa.", std1.name, std1.age, std1.gpa);  
    
    return 0; 


}