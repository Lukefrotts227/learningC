#include <iostream> 


using namespace std; 
int main(void)
{   
    int number, check; 

    cout << "Enter the number: "; 
    cin >> number; 

    cout << "Enter the number you are comparing to: ";
    cin >> check; 

    if (number == check){
        cout << number << " is equal to " << check << endl;
    }
    else if (number > check){
        cout << number << " is greater than " << check << endl; 
    }
    else{
        cout << number << " is less than " << check << endl;
    }


    // good job getting to here
    return 0; 
}

