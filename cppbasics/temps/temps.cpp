#include <iostream> 

using namespace std; 

template <typename T>
T add(T a, T b){
    return a + b; 
}

template <typename T>
T subtract(T a, T b){
    return a - b;
}

template <typename T>
T multi(T a, T b){
    return a * b;
}

template <typename T>
T divs(T a, T b){
    if(b != 0){
        return a / b; 
    }else{
        cerr << "Error: Divided by zero\n"; 
        return static_cast<T>(0);
    }
}

template <typename T> 
T grabNum(){
    T number; 
    cout << "Enter the number: "; 
    cin >> number; 
    return number; 
}

template <typename T> 
void giveAdd(T a, T b){
    cout << "Sum: " << add(a, b) << "\n"; 
}

template <typename T> 
void giveSub(T a, T b){
    cout << "Difference: " << subtract(a, b) << "\n";
}

template <typename T>
void giveMult(T a, T b){
    cout << "Multiplied: " << multi(a, b) << "\n"; 
}

template <typename T>
void giveDiv(T a, T b){
    cout << "Divided: " << divs(a, b) << "\n"; 
}


int main(void){
    int intNum1 = grabNum<int>();
    int intNum2 = grabNum<int>();
    giveAdd(intNum1, intNum2);
    giveSub(intNum1, intNum2);
    giveMult(intNum1, intNum2);
    giveDiv(intNum1, intNum2);

    double doubleNum1 = grabNum<double>();
    double doubleNum2 = grabNum<double>();
    giveAdd(doubleNum1, doubleNum2);
    giveSub(doubleNum1, doubleNum2);
    giveMult(doubleNum1, doubleNum2);
    giveDiv(doubleNum1, doubleNum2);

    

}