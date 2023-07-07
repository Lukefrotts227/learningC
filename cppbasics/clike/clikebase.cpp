#include <iostream> 
#include <string>

using namespace std; 

int main(int argc, char *args[])
{
    if (argc > 3)
    {
        cout << "too many args \n"; 
        return 1; 
    }
    if (argc < 3)
    {
        cout << "too few args \n";
        return 1;
    }

    string name(args[1]);
    int age = stoi(args[2]); 

    cout << name << " you are " << age << " years old.\n"; 

    

    return 0;

}