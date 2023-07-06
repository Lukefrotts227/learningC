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
    if (toLower(str).compare("yes") ){
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
};


class Student{
    private: 
        string name; 
        
    public: 
        string outputdata(){

        return "";
        }
};

class Course {

    private: 
        string className; 
        string teacherName; 
         
        int gradeNumber;
        fstream file; 
        vector<Student> students;

    public: 

        Course(int numS, int numG){
            
            gradeNumber = numG; 
            file.open("metaclass.csv", ios::app); 
        }

        void addStudent(Student student){
             
             students.push_back(student); 
        }
        void updateCSV(){
            file.open("class.csv", ios::app);
            for (int i = 0; i < students.size(); i++){
                //file << students[i].outputdata(); 
            }

        }
        
};



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

