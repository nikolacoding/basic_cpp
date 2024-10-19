#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int numberSyllables(string word){
	int number = 1;	
	
	for (int i = 0; i < word.length(); i++){

		if (word[i] == '-'){
			number++;
		}
	}
	
	return number;
}
	

int main(){	

	cout << numberSyllables("amo-gus-gus");
	 
	return 0;
}


