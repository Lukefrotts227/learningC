#include "batch.h"

#include <iostream>
#include <string> 
using namespace std; 

int main() {
    person p1("Alice", 25, 160, 55, "A programmer.");
    person p2("Bob", 30, 175, 70, "An artist.");

    group g1;
    g1.addPerson(p1);
    g1.addPerson(p2);

    vector<person> peopleVector = {p1, p2};
    group g2;
    g2 = peopleVector; // Assign vector of people to group

    // Printing the people in g1 using the person class's print() method
    for (const person& p : g1.getpeople()) {
        p.print();
        cout << endl;
    }

    return 0;
}

