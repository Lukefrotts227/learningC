/* here we will be looking at maps and unorderd maps in cpp */
#include <string> 
#include <iostream>
#include <fstream> 
#include <vector>  
#include <unordered_map> 
#include <map> 
#include "standards.h"
#include <chrono>



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
    

    map<string, int> myMap; 
    auto start = chrono::high_resolution_clock::now(); 
    for(size_t i = 0; i < namesArray.size(); ++i){
        myMap[namesArray[i]] = numbersArray[i]; 
    }
    auto end = chrono::high_resolution_clock::now(); 
    chrono::duration<double> duration = end - start; 

    cout << "map insert " << duration.count() << " seconds\n"; 

    start = chrono::high_resolution_clock::now(); 

    for(const auto& name : namesArray){
        int value = myMap[name]; 
    }
    end = chrono::high_resolution_clock::now(); 

    duration = end - start; 
    cout << "map access time: " << duration.count() << "seconds\n"; 

    unordered_map<string, int> myUnorderedMap; 
    start = chrono::high_resolution_clock::now(); 

    for(size_t i = 0; i < namesArray.size(); ++i){
        myUnorderedMap[namesArray[i]] = numbersArray[i]; 
    }

    end = chrono::high_resolution_clock::now(); 

    duration = end - start; 
    cout << "unordered map insert time: " << duration.count() << "seconds\n"; 

    start = chrono::high_resolution_clock::now(); 
    for(const auto& name : namesArray){
        int value = myUnorderedMap[name]; 
    }

    end = chrono::high_resolution_clock::now(); 
    duration = end - start; 

    cout << "unorderd map  access time: " << duration.count() << "seconds\n"; 
    








    return 0; 
}