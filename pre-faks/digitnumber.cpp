#include <iostream>
#include <string>

using namespace std;

int num_of_digits(int number){
	string numberString = to_string(number);
	
	int temp = 0;
	
	for (int i = 0; i < numberString.length(); i++){
		temp++;
	}
	
	return temp;
}

int main(){
	int no;
	cin >> no;
	cout << num_of_digits(no);
	return 0;
}
