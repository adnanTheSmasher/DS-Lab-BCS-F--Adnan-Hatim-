#include <iostream>
#include <cstring>
using namespace std;


class Exam
{
    private:
        char* student_name;
        char* date;
        int score;
    
    public:
        Exam(){};
        
        void set_exam_details(const char* name, const char* d, const int scor)
        {
            student_name = new char[strlen(name) + 1];
            strcpy(student_name, name);

            date = new char[strlen(d) + 1];
            strcpy(this->date, d);

            score = scor;
        }


    void display() const {
        cout << "Student Name: " << student_name << endl;
        cout << "Exam Date: " << date << endl;
        cout << "Score: " << score << endl;
    }

    ~Exam()
    {
        delete[] student_name;
        delete[] date;
    }

};

int main()
{
    Exam e1;

    e1.set_exam_details("Adnan", "9/oct/2025", 100);

    e1.display();

    Exam e2;
    e2 = e1;

    e2.display();

}