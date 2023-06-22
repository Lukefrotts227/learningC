#include <iostream> 
#include <string>
#include <vector>
#include <fstream>


using namespace std;
bool keepgoing = true; 
std::fstream file;
class Student{

};

class Course {

    private: 
        std::string className; 
        std::string teacherName; 
        int studentNumber; 
        int gradeNumber;
        std::vector<Student> students;

    public: 

        Course(int numS, int numG){
            studentNumber = numS; 
            gradeNumber = numG; 
            file.open("class.csv", std::ios::app); 
        }

        void addStudent(Student student){
             
        }
        void updateCSV(){
            file.open("class.csv", std::ios::app);

        }
        
};



// function to reset everything
void reset(){

}

// the main function
int main(void){

    while (keepgoing == true){

    }

    return 0; 
}

