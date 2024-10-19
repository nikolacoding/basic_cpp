#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
	for (int i = 0; i < 25; i++){
		cout << rand() % 20 << endl;
	}
}

