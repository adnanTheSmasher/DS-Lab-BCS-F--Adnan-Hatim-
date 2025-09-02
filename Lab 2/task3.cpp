/*
Task #3:  
Design a program to handle marks of students in different courses using a jagged array (since each student is enrolled in a different number of courses).  
=> Input the number of courses each student takes.  
=> Dynamically allocate memory for each student accordingly.  
=> Calculate and display each student’s average marks.
*/


#include <iostream>
using namespace std;

int main() {
    int students, input;
    
    cout<< "Enter number of students: ";
    cin >> students;
    
    
    
    int **arr = new int*[students]{0};
    int courses[students];

    for (int i = 0; i < students; i++) {
        cout << "Enter number of courses for student: " << i + 1 << " : ";
        cin >> courses[i];
        arr[i] = new int[courses[i]];
    }


    for (int i = 0; i < students; i++) {
        for (int j = 0; j < courses[i]; j++) {
        	while (true){
	        	cout << "enter course" << j+1 << " marks for student "<< i+1<< ": ";
	            cin >> input;
				if ((input >= 0) && (input <= 100))
				{
					arr[i][j] = input;
					break;	
				}    		
				else
				{
					cout << "Marks should be between 0 to 100...\n";
				}
			}
        }
        cout << endl;
    }
    
    for (int i=0; i<students; i++)
    {
    	for(int j=0; j<courses[i]; j++)
    	{
    		cout<< "Student " << i+1 << " for course" << j+1 << " is: "<< arr[i][j] << "\n";
		}
		cout<<"\n";
	}


	
	
    for (int i = 0; i < students; i++) {
        delete[] arr[i]; 
    }
    
    delete[] arr; 

    return 0;
}