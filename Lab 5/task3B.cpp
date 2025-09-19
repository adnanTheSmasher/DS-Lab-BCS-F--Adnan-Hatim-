#include<iostream>
using namespace std;

int sumNonTail(int n)
{
	if(n==0){
		return 0;
	}
	else{
		return n + sumNonTail(n-1);
		
	}
}

int main(){
	int num;
	int total;
	cout<< "Enter Number: ";
	cin >> num;
	
	cout<< sumNonTail(num);
	
}