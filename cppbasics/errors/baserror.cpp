#include <iostream> 

using namespace std; 


int main(void)
{
    int num_test; 
    cout << "Enter an integer: "; 
    cin >> num_test; 

    try {
        cout << "trying...\n";

        if (num_test < 0){

            throw num_test; 
            cout << "got it\n";
        }

    }
    catch (int num_test){
        cout << "Exception: number should be positive";
        // return a value of 1 if error
        return 1; 
    }
    cout << "End of program. passed"; 

    return 0; 
}