#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

class person{
    private: 
        string name; 
        int age; 
        int height; 
        int weight; 
        string description; 
        
    public: 

        person(string n, int a, int h, int w, string d) : name(n), age(a), height(h), weight(w), description(d) {}


        string getName(){
            return name; 
        }
        void setName(string n){
            name = n; 
        }

        int getAge(){
            return age; 
        }
        void setAge(int a){
            age = a; 
        }

        int getHeight(){
            return height; 
        }
        void setHeight(int h){
            height = h; 
        }

        int getWeight(){
            return weight;
        }
        void setWeight(int w){
            weight = w; 
        }

        string getDescription(){
            return description; 
        }
        void setDescription(string d){
            description = d; 
        }

        friend ostream& operator<<(ostream& os, const person& obj){
            os << obj.name; 
            return os; 
        }

        void print() const {
            cout << "name: " << name << '\n'; 
            cout << "age: " << age << '\n';
            cout << "height: " << height << '\n'; 
            cout << "weight: " << weight << '\n'; 
            cout << "description: " << description << '\n'; 
        }

};

class group{

    private:
        vector<person> people; 

    public: 
        group(vector<person> p) : people(p) {}
        group() {} 



        vector<person> getpeople(){
            return people; 
        }
        
        void addPerson(person pers){
            people.push_back(pers);
        }

        int size(){
            return people.size(); 
        }

        group& operator=(const group& other){
            people = other.people; 
            return *this; 

        }
        group& operator=(const vector<person> pers){
            people = pers; 
            return *this; 

        }

        void print(){
            for(const person& p : getpeople()){
                p.print(); 
                cout << '\n'; 
            }
        }

        


};