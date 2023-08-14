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

class Assignment{
    private:  
        string name; 
        int weight; 
        int grade; 
    public: 
        Assignment(string n, int w, int g){
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
        vector<Assignment> grades; 
        
    public: 
        void addGrade(Assignment grade){
            grades.push_back(grade); 
        }

        string getName(){

        }

        vector<Assignment> getGrades(){

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
        string getClassName(){

        }
        string getTeacherName(){

        }
        int getGradeNumber(){

        }
        vector<Student> getStudents(){

        }

};

Course myCourse; 

// load the data from the csv into the program
void load_data()
{
    fstream fileno;
    fstream file; 
   
    fileno.open("empty.txt"); 

    char ch; 
    char empty;

    file.get(ch); 
    empty = ch; 
    if (empty == 'y'){

        file.open("class.csv", ios::out); 
        
        // data load logic 
    }
    fileno.close(); 
    

}

// update the data on the csv file 
void update_data()
{
    fstream file; 
    
    file.open("class.csv", ios::out); 

    
    file.close(); 


    

}


// function to reset everything
void reset(){
    fstream file; 
     
    file.open("class.csv", ios::out); 
    

    file.close(); 
      

}

// the main function
int main(void){
    bool keepgoing = true; 

    // main loop of the program; 

    while (keepgoing == true){
        
    }

    return 0; 
}

