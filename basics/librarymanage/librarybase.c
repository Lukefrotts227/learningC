#include <stdio.h> // for the input output
#include <stdbool.h> // to check if the book has been taken out or not
#include <string.h> // in order to build the struct properly


// creating a libray management project in c

// creating structs and globals

// the information for the indivdual book
struct book{ 
    char book_name[50]; 
    char author_name[50];
    int pages; 
    bool isOut; 
    int bookid; 
    float price; 
};

struct book library[0]; 


struct book createBook(char b_name[50], char auth_name[50], int p, int id, float price){
    struct book s; 
    strcpy(s.book_name, b_name); 
    strcpy(s.author_name, auth_name); 
    s.pages = p; 
    s.isOut = false; 
    s.bookid = id; 
    s.price = price; 
    return s; 
}

void addToLibrary(struct book b){
    

}

// beginning implemenation will be with a simple array
int main(){

    // including 5 base books to start


    return 0; 
}