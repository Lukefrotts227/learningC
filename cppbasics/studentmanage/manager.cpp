#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype> 
#include <sstream> 
#include <algorithm>

#define FILENAME "class.txt"


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
            return name; 
        }

        vector<Assignment> getGrades(){
            return grades; 
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
            return className; 

        }
        string getTeacherName(){
            return teacherName; 
        }
        int getGradeNumber(){
            return gradeNumber; 
        }
        vector<Student> getStudents(){
            return students; 
        }
        void setTeacherName(string teacher){
            teacherName = teacher; 
        }
        void setClassName(string classe){
            className = classe;
        }

};

bool isEmpty(fstream& pFile){
    return pFile.peek() == fstream::traits_type::eof(); 
}

Course myCourse(22, 24); 

// load the data from the csv into the program
bool load_data()
{
    
    fstream file; 



    

    file.open(FILENAME, ios::in); 

    if (isEmpty(file)){
        file.close(); 
        return false;
    }

    string line; 
    file.ignore(); 
    getline(file, line,')'); 
    myCourse.setTeacherName(line); 
    file.ignore(); 
    getline(file, line, ')');   
    myCourse.setClassName(line); 


    file.close(); 
    return true; 




   
    

}

// update the data on the csv file 
void update_data()
{
    fstream file; 
    
    file.open(FILENAME, ios::out); 

    // update the data below
    string name = myCourse.getTeacherName(); 
    string cName = myCourse.getClassName(); 

    file << '(' << name << ')' << '(' << cName << ')'; 

    
    file.close(); 


    

}


// function to reset everything
void reset(){
    fstream file; 
     
    file.open(FILENAME, ios::out); 
    

    file.close(); 
      

}

// the main function
int main(void){
    bool keepgoing = true; 

    // main loop of the program; 

    while (keepgoing == true){
        
        load_data(); 
        cout <<  "og teacher name: " << myCourse.getTeacherName() << '\n'; 
        cout << "og class name: " << myCourse.getClassName() << '\n'; 
        string n; 
        string c; 

        cout << "Enter the the teacher name: "; 
        getline(cin, n); 

        cout << "Enter the class name: "; 
        getline(cin, c);  

        myCourse.setTeacherName(n); 
        myCourse.setClassName(c); 

        update_data(); 
        


        keepgoing = false; 
    }

    return 0; 
}

