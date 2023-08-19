/* here we will be looking at maps and unorderd maps in cpp */
#include <string> 
#include <iostream>
#include <fstream> 
#include <vector>  
#include <unordered_map> 
#include <map> 
#include "standards.h"



using namespace std; 


vector<string> getKeys(){
    vector<string> namesArray = readLines("names.txt"); 
    return namesArray; 
}

vector<int> getValues(){
    vector<int> numbersArray = genRandomInt(100, 0, 888); 
    return numbersArray; 
}


int main(void){
    vector<string> namesArray = getKeys(); 
    vector<int> numbersArray = getValues(); 

    





    return 0; 
}