#include <iostream> 
#include <string> 
#include "rpg.h"

using namespace std; 

int main(){
    key_init(); 
    cout << *keywords["strength"] << '\n'; 

    return 0; 
}