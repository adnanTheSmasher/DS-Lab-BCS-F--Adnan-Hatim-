#include<iostream>
using namespace std;

int sumTail(int n, int total)
{
	if(n==0){
		return total;
	}
	else{
		total += n;
		return sumTail(n-1, total);
	}
}

int main(){
	int num;
	int total;
	cout<< "Enter Number: ";
	cin >> num;
	
	cout<< sumTail(num, total);
	
}