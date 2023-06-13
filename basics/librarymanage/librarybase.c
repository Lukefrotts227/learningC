#include <stdio.h> // for the input output
#include <stdbool.h> // to check if the book has been taken out or not



// creating a libray management project in c

// creating struct

// the information for the indivdual book
struct book{ 
    char book_name[50]; 
    char author_name[50];
    int pages; 
    bool isOut; 
    int bookid; 
    float price; 
};


// beginning implemenation will be with a simple array

int main(){
    struct book library[12]; 


    return 0; 
}