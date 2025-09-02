/*
Task #2:
WWrite a program that uses a dynamic 2D array to represent a seating chart in a classroom.

=> benches represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form.*/


#include <iostream>
using namespace std;

int main() {
    int benches, seats, input;
    
	cout << "Enter number of benches: ";
    cin >> benches;
    cout << "Enter number of seats each bench has: ";
    cin >> seats;
    

    
    int** arr = new int*[benches]; 
    for (int i = 0; i < benches; i++) {
        arr[i] = new int[seats]{0}; 
    }
	
    cout<< "if seat is occupied enter 1 else 0.\n";
    for (int i = 0; i < benches; i++) {
    	cout<< "For Bench: " << i+1<<"\n";
        for (int j = 0; j < seats; j++) 
		{
			while (true){
		
				cout<< "seat: "<< j+1<<"\n";
	            cin >> input;
	            if ((input == 0) || (input == 1))
	            
	            {
	            	arr[i][j] = input;
	            	break;
				}
				else
				{
					cout << "not valid input enter 0 or 1....\n";	
				}
				            
			}
        }
    }

    cout << "ClassRoom chart:\n";
    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
            cout << arr[i][j] << ".";
        }
        cout << endl;
    }

    for (int i = 0; i < benches; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
