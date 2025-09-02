/*
Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.
*/


#include <iostream>
using namespace std;



int main() {
    int departments;
    
    cout<< "Enter number of departments: ";
    cin >> departments;
    
    
    
    int **arr = new int*[departments]{0};
    int employeSize[departments];

    for (int i = 0; i < departments; i++) {
        cout << "Enter number of Employee for Department: " << i + 1 << ": ";
        cin >> employeSize[i];
        arr[i] = new int[employeSize[i]];
    }


    for (int i = 0; i < departments; i++) {
        for (int j = 0; j < employeSize[i]; j++) {
	        	cout << "Enter Employee " << j+1 
                 << " Salary of Department " << i+1 << ": ";
                cin >> arr[i][j];    		
        }
        cout << endl;
    }

    cout << "\nHighest salary in each department:\n";
    for (int i = 0; i < departments; i++) {
        int highest = arr[i][0];
        for (int j = 1; j < employeSize[i]; j++) {
            if (arr[i][j] > highest) {
                highest = arr[i][j];
            }
        }
        cout << "Department " << i+1 << ": " << highest << endl;
    }
	
	double maxAvg = 0;
    int maxDept = 0;

    for (int i = 0; i < departments; i++) {
        int sum = 0;
        for (int j = 0; j < employeSize[i]; j++) {
            sum += arr[i][j];
        }
        double avg = (double)sum / employeSize[i];
        if (avg > maxAvg) {
            maxAvg = avg;
            maxDept = i;
        }
    }

    cout << "\nDepartment with maximum average salary: Department " 
         << maxDept + 1 << " (Average = " << maxAvg << ")\n";


    for (int i = 0; i < departments; i++) {
        delete[] arr[i]; 
    }
    
    delete[] arr; 

    return 0;
}