#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype> 
#include <algorithm>


using namespace std;

string toLower(const string &str)
{
    string lower = str; 
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    return lower;
}

bool contY(string str)
{
    if (toLower(str).compare("yes") || toLower(str).compare("y") || toLower(str).compare("true")){
        return true; 
    }
    else {
        return false;
    }
}

bool contN(string str){
    if(true){
        return false;
    }
    else {
        return true; 
    }
}

bool keepgoing = true; 

class Assingment{
    private:  
        string name; 
        int weight; 
        int grade; 
    public: 
        Assingment(string n, int w, int g){
            name = n; 
            weight = w; 
            grade = g; 

        }
        string getName(){
            return name;
        }

        int getWeight(){
            return weight;
        }

        int getGrade(){
            return grade; 
        }
};


class Student{
    private: 
        string name; 
        vector<Assingment> grades; 
        
    public: 
        string outputdata(){

        return "";
        }
        void addGrade(Assingment grade){
            grades.push_back(grade); 
        }
};

class Course {

    private: 
        string className; 
        string teacherName; 
         
        int gradeNumber;
        vector<Student> students;

    public: 

        Course(int numS, int numG){
            
            gradeNumber = numG; 
        }

        void addStudent(Student student){
             
             students.push_back(student); 
        }

};

Course myCourse; 

// load the data from the csv into the program
void load_data()
{
    fstream fileno;
    fstream file; 
    fstream file2; 

    fileno.open("empty.txt"); 

    char ch; 
    char empty;

    file.get(ch); 
    empty = ch; 
    if (empty == 'y'){

        file.open("class.csv", ios::out); 
        file2.open("metaclass.csv", ios::out);
        // data load logic 
    }
    fileno.close(); 
    

}

// update the data on the csv file 
void update_data()
{
    fstream file; 
    fstream file2; 

    file.open("class.csv", ios::out); 
    file2.open("metaclass.csv", ios::out);

}


// function to reset everything
void reset(){
    fstream file; 
    fstream file2; 
    file.open("class.csv", ios::out); 
    file2.open("metaclass.csv", ios::out);

    file.close(); 
    file2.close();  

}

// the main function
int main(void){
    // main loop of the program; 
    while (keepgoing == true){
        
    }

    return 0; 
}

