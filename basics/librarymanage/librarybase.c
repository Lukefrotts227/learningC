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

struct book library[400]; 
int libSize = 0; 
FILE *fp; 


// the ability to print an array of unknown size
// for future improve pointer knowledge in c



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
    // add book item to the right place
    library[libSize] = b; 

    // increase the size of the libSize
    libSize++; 

}

// Code to store the library in a seperate file
void storeLibray(){
    


}

// pull data from the seperate library file
void pullLibrary(){

}

// beginning implemenation will be with a simple array
int main(){
    printf("Max of 400 books in the library\n"); 

    // including 3 base books for testing
    addToLibrary(createBook("John's story", "John Doe", 65, 0001, 56.32)); 
    addToLibrary(createBook("Jane's story", "Jane Doe", 77, 0002, 16.32)); 
    addToLibrary(createBook("Bob's story", "Bob Doe", 44, 0003, 26.32));

    for (int i = 0; i < libSize; i++){
        printf("%s\n", library[i].book_name); 
    }




    return 0; 
}