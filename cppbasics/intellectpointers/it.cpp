#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <memory> 

using namespace std; 

class myData{
    private: 
        vector<int> data1; 
        vector<string> data2; 

    public: 
        myData() {}
        myData(vector<int> i) : data1(i) {}
        myData(vector<string> d) : data2(d) {}
        myData(vector<int> i, vector<string> d) : data1(i), data2(d) {}

        vector<int> getData1() { return data1; }
        vector<string> getData2() { return data2; }

        void setData1(vector<int> d) { data1 = d; }
        void setData2(vector<string> d) { data2 = d; }

        void operator=(const myData& other){
            data1 = other.data1; 
            data2 = other.data2; 
        }

        friend ostream& operator<<(ostream& os, myData& obj){
            os << '['; 
            for(int i = 0; i < obj.data1.size() - 1 ; i++){
                os << obj.data1[i] << ", "; 
            }
            os << obj.data1[obj.data1.size()-1]; 
            os << "]\t["; 
            for(int i = 0; i < obj.data2.size() - 1; i++){
                os << obj.data2[i] << ", "; 
            }
            os << obj.data2[obj.data2.size()-1]; 
            os << ']'; 
            return os; 
        }

        

}; 


int main(){
    vector<int> part1 = {3, 4, 5, 1, 6, 8, 2, 5, 2, 8, 9, 4, 9}; 
    vector<string> part2 = {"joe", "jin", "jay", "jell", "jian", "yang", "yao"}; 

    vector<int> part3 = {3, 5, 7, 1, 2, 5}; 
    vector<string> part4 = {"billy", "juan", "el dianlo", "rico"}; 

    const char * cstring = "hello there "; 
    cout << cstring << '\n'; 
    cout << "and then we are\n";

    unique_ptr<myData> ptr(new myData(part1, part2)); 
    shared_ptr<myData> ptr2(new myData(part3, part4)); 


    cout << "the data : " << *ptr << '\n'; 

    return 0; 
}