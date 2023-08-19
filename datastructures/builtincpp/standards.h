#include <vector> 
#include <string> 
#include <iostream> 
#include <fstream> 
#include <random> 


using namespace std; 

vector<string> readLines(const string& filename){
    ifstream inputFile(filename); 

    vector<string> names; 


    if(inputFile.is_open()){
        string line; 
        while(getline(inputFile, line)){
            names.push_back(line); 
        }
        inputFile.close(); 
        return names; 
    }

    cerr << "Error in the opening of the file \n"; 
    return names; 
}


vector<int> genRandomInt(int count, int min, int max){
    vector<int> randomNumbers; 

    random_device rd; 
    mt19937 generator(rd()); 

    uniform_int_distribution<int> dist(min, max); 

    for(int i = 0; i < count; i++){
        randomNumbers.push_back(dist(generator)); 
    }
    return randomNumbers; 
}
