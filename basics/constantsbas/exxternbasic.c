#include <stdio.h>

extern int hours;
extern int minutes;
extern int seconds;


int main(){
    int hours = 3; 
    int minutes = 12;
    int seconds = 33;
    int total = hours*3600 + minutes*60 + seconds; 
    printf("This many Seconds : %i", total);
    return 0;
}