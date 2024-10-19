#include <iostream>
#include <string>

using namespace std;

string longBurp(int length){
	string temp = "Bu" + string(length, 'r') + "p";
	
	return temp;
}

int main(){
	int burpLength;
	cout << "Enter the burp length: ";
	cin >> burpLength;
	
	cout << "\n" << longBurp(burpLength);
	return 0;
}
