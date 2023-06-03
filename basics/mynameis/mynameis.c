#include <stdio.h>
int main() {
    char name[66]; 
    printf("Enter your name please:"); // ask for the name
    scanf("%s", name); // get the name
    printf("Your name is %s\n", name); // print the name
    return 0;
}