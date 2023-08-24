#include "batch.h"

#include <iostream>
#include <string> 
#include <vector> 
using namespace std; 

int main() {
    person p1("Alice", 25, 160, 55, "A programmer.");
    person p2("Bob", 30, 175, 70, "An artist.");
    person p3("John", 32, 188, 88, "A drug dealer."); 


    group g1;
    
    g1.addPerson(p1);
    g1.addPerson(p2);

    vector<person> peopleVector = {p1, p2, p3};
    group g2;
    g2 = peopleVector; // Assign vector of people to group

    // Printing the people in g1 using the person class's print() method
    g1.print(); 
    g1 = g2; 
    g1.print(); 

    cout << g1.size() << '\n'; 

    return 0;
}

