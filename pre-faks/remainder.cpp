#include <iostream>

using namespace std;

int remainder(int dividend, int divisor){
	return dividend % divisor;
}

int main(){
	
	int dividend;
	int divisor;
	
	cout << "Enter the dividend: ";
	cin >> dividend;
	cout << "Enter the divisor: ";
	cin >> divisor;
	
	cout << remainder(dividend, divisor);
	return 0;
}
