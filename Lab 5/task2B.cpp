#include<iostream>
using namespace std;

int printNumbers(int n);

printNumeberAndDecrement(int n)
{
	if (n==1){
		return 1;
	}
	else{
		cout<< n;
		printNumbers(n-1);
	}
}

int printNumbers(int n){
	if (n == 1){
		return 1;
	}
	else{
		cout << n;
		printNumeberAndDecrement(n-1);
	}
}

int main(){
	int num;
	cout<< "Enter Number: ";
	cin >> num;
	
	cout<< printNumbers(num);
	
	
}