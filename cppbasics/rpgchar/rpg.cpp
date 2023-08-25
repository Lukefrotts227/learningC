#include <iostream> 
#include <string> 
#include "rpg.h"

using namespace std; 

int main(){
    key_init(); 
    cout << *keywords["strength"] << '\n' << *keywords["speed"] << '\n' << keywords["durability"] << '\n'; 

    return 0; 
}