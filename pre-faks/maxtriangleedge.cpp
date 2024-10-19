#include <iostream>

using namespace std;

int nextEdge(int first, int second){
	return first + second - 1;
}

int main(){
	
	int a,b;
	
	cin >> a;
	cin >> b;
	
	cout << nextEdge(a, b);
	
	return 0;
}
