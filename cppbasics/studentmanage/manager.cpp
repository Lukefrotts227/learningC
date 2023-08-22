#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype> 
#include <sstream> 
#include <algorithm>

#define FILENAME "class.txt"


/* convention: 
withing the text file paraenthesis will indicate new data
*/


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
        double weight; 
        double grade; 
    public: 
        Assignment(string n, double w, double g){
            name = n; 
            weight = w; 
            grade = g; 

        }
        string getName(){
            return name;
        }

        double getWeight(){
            return weight;
        }

        double getGrade(){
            return grade; 
        }
};


class Student{
    private: 
        string name; 
        vector<Assignment> grades; 
        
    public: 

        Student(string s) : name(s){}
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
         
        vector<Student> students;

    public: 

        void addStudent(Student student){
             
             students.push_back(student); 
        }
        string getClassName(){
            return className; 

        }
        string getTeacherName(){
            return teacherName; 
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

Course myCourse; 

// load the data from the csv into the program
bool load_data()
{
    
    fstream file; 



    

    file.open(FILENAME, ios::in); 

    if (isEmpty(file)){
        file.close(); 
        return false;
    }
    
    string line, teacherName, className; 
    
    char openPar; 
    getline(file, line); 
    istringstream linestream(line);
    linestream >> openPar; 
    getline(linestream, teacherName, ')'); 
    linestream >> openPar; 
    getline(linestream, className, ')'); 
    linestream >> openPar; 
    myCourse.setTeacherName(teacherName); 
    myCourse.setClassName(className); 

   while (getline(file, line, '\n')) {
    istringstream linestream(line);
    string studentName;
    getline(linestream, studentName, ')');
    Student student(studentName);

    string assignmentName;
    double gradeNumber, gradeWeight;

    while (getline(linestream, assignmentName, ')')) {
        linestream.ignore(); // Ignore the space after the assignment name '('
        linestream >> gradeNumber;
        linestream.ignore(); // Ignore the space after the grade number '('
        linestream >> gradeWeight;
        linestream.ignore(); // Ignore the space after the grade weight ')'

        Assignment assignment(assignmentName, gradeNumber, gradeWeight);
        student.addGrade(assignment);
    }

    myCourse.addStudent(student);
}





    file.close(); 
    return true; 

    

}

// update the data on the csv file 
bool update_data()
{
    fstream file; 
    
    file.open(FILENAME, ios::out); 

    // update the data below
    string name = myCourse.getTeacherName(); 
    string cName = myCourse.getClassName(); 

    file << '(' << name << ')' << '(' << cName << ')' << '\n'; 

    for(int i = 0; i < myCourse.getStudents().size(); i++){
        file << '(' << myCourse.getStudents()[i].getName() << ')';
        for(int j = 0; j < myCourse.getStudents()[i].getGrades().size(); j++){
            file << '(' << myCourse.getStudents()[i].getGrades()[j].getName() << ')'; 
            file << '(' << myCourse.getStudents()[i].getGrades()[j].getGrade() << ')'; 
            file << '(' << myCourse.getStudents()[i].getGrades()[j].getWeight() << ')'; 
        }
        file << '\n'; 
    }
    
    file.close(); 


    return true; 

}


// function to reset everything
bool reset(){
    fstream file; 
     
    file.open(FILENAME, ios::out); 
    

    file.close(); 
    
    return true;  

}

// the main function
int main(void){
    bool keepgoing = true; 

    // main loop of the program; 

    while (keepgoing == true){
        
        bool stuff = load_data(); 
        if(stuff == true){
            cout <<  "og teacher name: " << myCourse.getTeacherName() << '\n'; 
            cout << "og class name: " << myCourse.getClassName() << '\n'; 
            cout << "ranodm student: " << myCourse.getStudents()[0].getName() << '\n'; 

        }

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

