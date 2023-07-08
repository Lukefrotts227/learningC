#include <iostream> 
#include <string> 

using namespace std; 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {

        cout << "error invalid cmd args\n"; 
        return 1;
    }
    cout << "testing\n";

    // passed without error
    return 0; 

}