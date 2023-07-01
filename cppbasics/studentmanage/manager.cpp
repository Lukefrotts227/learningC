#include <iostream> 
#include <string>
#include <vector>
#include <fstream>


using namespace std;
bool keepgoing = true; 

class Student{
    private: 
        std::string name; 
    public: 
        string outputdata(){

        return "";
        }
};

class Course {

    private: 
        std::string className; 
        std::string teacherName; 
        int studentNumber; 
        int gradeNumber;
        std::fstream file; 
        std::vector<Student> students;

    public: 

        Course(int numS, int numG){
            studentNumber = numS; 
            gradeNumber = numG; 
            file.open("metaclass.csv", std::ios::app); 
        }

        void addStudent(Student student){
             
        }
        void updateCSV(){
            file.open("class.csv", std::ios::app);
            for (int i = 0; i < students.size(); i++){
                file << students[i].outputdata(); 
            }

        }
        
};



// function to reset everything
void reset(){
    fstream file; 
    fstream file2; 
    file.open("class.csv", std::ios::); 
    file2.open("metaclass.csv", std::ios::);

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

