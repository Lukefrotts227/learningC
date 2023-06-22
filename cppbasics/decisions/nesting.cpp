#include <iostream>

using namespace std; 

int main(void){
    int num;
    cout << "Enter a integer: "; 
    cin >> num; 

    if (num != 0)
    {
        if (num > 0){
            cout << "The number is positive." << endl; 

        }

        else {
            cout << "The numbe is negative" << endl; 
        }
    }
    else {
        cout << "The number is 0" << endl; 
    }


    // if it passes
    return 0; 
}