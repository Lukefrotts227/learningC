#include <iostream> 
#include <thread> 
#include <vector> 


using namespace std;


// return all of the factorial answers
void print_all(vector<int> ans)
{
    cout << "The factorials in order are... \n"; 
    for (int n : ans){
        cout << n << " "; 
    }
    cout << "\n thats all!! \n"; 

}


// calculate the factorial of a given number using a standard recursive function
int factorial(int number)
{   
    if (number == 0){
        return 1; 
    }
    return number * factorial(number - 1); 

}

vector<int> get_port(int begin, int end, vector<int> og){

    vector<int> newvec; 

    for (int i = begin; i < end; i++){
        int answer = factorial(og[i]); 
        newvec.push_back(answer); 
    }

    return newvec; 
}



 
int main(int argc, char *argv[])
{

    vector<int> nums; 

    for(int i = 1; i < argc; i++)
    {
        int num = stoi(argv[i]); 
        nums.push_back(num); 
    }
    int start1 = 1; 
    int start2 = (argc/2) + 1; 
    int end1 = start2; 
    int end2 = argc; 



    return 0; 
}