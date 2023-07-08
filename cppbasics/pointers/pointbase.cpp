#include <iostream> 
#include <string> 
#include <windows.h> 
#include <unistd.h> 

using namespace std; 
int main(int argc, char *argv[])
{
    string item(argv[1]); 
    //pointer to item
    string *ptr = &item; 


    if (argc != 2)
    {

        cout << "error invalid cmd args\n"; 
        return 1;
    }
    cout << "testing\n";
    sleep(1); 

    cout << "your input was " << item << "\n"; 

    cout << "it is located at " << ptr << "\n";
    

    // passed without error
    return 0; 

}