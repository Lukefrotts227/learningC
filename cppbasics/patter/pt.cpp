#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

struct Person{
    string name; 
    int age;
    int height; 
    int weight; 
}; 

class House{

    private: 
        vector<Person*> people; 
        int size; 

    public:
        House(vector<Person*> p, int s) : people(p), size(s){}

        vector<Person*> getPeople(){
            return people; 
        }

        int getSize(){
            return size; 
        }
        
}; 

class Street{
    private: 
        vector<House*> houses; 
        string name; 

    public: 
        Street(vector<House*> h, string n) : houses(h), name(n){}

        vector<House*> getHouses(){
            return houses; 
        }
        string getName(){
            return name; 
        }
};

class Town{
    private: 
        vector<Street*> streets; 
        string name; 

    public: 
        Town(vector<Street*> s, string n) : streets(s), name(n){}

        vector<Street*> getStreets(){
            return streets; 
        }
        string getName(){
            return name; 
        }

};


void printPeople(Town town){
    for(int i = 0; i < town.getStreets().size(); i++){
        for(int a = 0; a < town.getStreets()[i]->getHouses().size(); a++){
            for(int j = 0; j < town.getStreets()[i]->getHouses()[a]->getPeople().size(); j++ ){
                Person * p = town.getStreets()[i]->getHouses()[a]->getPeople()[j]; 
                cout << "Name: " << p->name << " Age: " << p->age << " Height: " << p->height << " Weight: " << p->weight << "\n"; 
            }
        }
    }
}


int main() {
    // Creating people
    Person person1 = {"Alice", 25, 165, 60};
    Person person2 = {"Bob", 30, 180, 75};
    Person person3 = {"Charlie", 22, 175, 70};
    
    // Creating houses
    vector<Person*> house1_people = {&person1, &person2};
    vector<Person*> house2_people = {&person3};
    
    House house1(house1_people, 2);
    House house2(house2_people, 1);
    
    // Creating streets
    vector<House*> street1_houses = {&house1};
    vector<House*> street2_houses = {&house2};
    
    Street street1(street1_houses, "First Street");
    Street street2(street2_houses, "Second Street");
    
    // Creating town
    vector<Street*> town_streets = {&street1, &street2};
    Town town(town_streets, "My Town");
    
    // Printing people in the town
    printPeople(town);
    
    return 0;
}
