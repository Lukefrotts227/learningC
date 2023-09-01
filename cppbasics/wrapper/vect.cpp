#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 


template <typename Data>
class myVect{
    private:
        vector<Data> mine; 
    
    public: 
        myVect(vector<Data> it) : mine(it) {}
        myVect() {}

        template <std::size_t N>
        myVect(const Data (&array)[N]) : mine(array, array + N) {}

        vector<Data> getMine() { return mine; }
        void setMine(vector<Data> m) { mine = m; }

        void push_back(Data d){
            mine.push_back(d); 
        }

        void pop_back(){
            mine.pop_back(); 
        }
        
        bool empty(){
            return mine.empty();
        }
        void clear(){
            mine.clear(); 
        }

        int size(){
            return mine.size(); 
        }

        void operator=(const myVect other){
            mine = other.mine; 
        }

        Data at(int ind){
            return mine.at(ind); 
        }

        int capactiy(){
            return mine.capactiy(); 
        }

        friend ostream& operator<<(std::ostream& os, const myVect& obj) {
            os << '[';
            if (!obj.mine.empty()) {
                for (size_t i = 0; i < obj.mine.size() - 1; i++) {
                    os << obj.mine[i] << ", ";
                }
                os << obj.mine[obj.mine.size() - 1];
            }
            os << ']';
            return os;
        }

        void print(){
            int reducer = 4; 
            cout << '[';
            for(int i = 0; i < mine.size() - 1; i++){
                cout << mine[i] << ", "; 
                if(i % reducer == 0 && i != 0){
                    cout << '\n'; 
                }
            }
            cout << mine[mine.size()-1] << "]\n"; 
        }

        void print(int type){
            int reducer = 4; 
            
        }
        
        void print(int type, int reducer){

        }

};

int main(){
    myVect<string> me; 


    me.push_back("Billy"); 
    me.push_back("Johnny"); 
    me.push_back("Jian-Yang"); 
    me.push_back("Jose"); 
    me.push_back("Jesus"); 
    me.push_back("Diablo"); 
    me.push_back("Henric");
    me.push_back("Rico"); 

    cout << me << '\n'; 

    me.print(); 

    return 0; 
}