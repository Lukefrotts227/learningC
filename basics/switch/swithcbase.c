#include <stdio.h> 



// Grading system for test
int main(){
    int gpa_grade;
    char letter_grade; 
    printf("Enter the whole number gpa: "); 
    scanf("%i", &gpa_grade); 

    switch(gpa_grade){
        case 4: 
        letter_grade = 'A'; 
        break; 
        case 3: 
        letter_grade = 'B'; 
        break; 
        case 2: 
        letter_grade = 'C'; 
        break; 
        case 1: 
        letter_grade = 'D'; 
        break; 
        case 0: 
        letter_grade = 'F'; 
        break; 
        default: 
        letter_grade = 'F'; 
        
    }

    printf("The letter grade is: %c", letter_grade); 
 
    return 0; 

}