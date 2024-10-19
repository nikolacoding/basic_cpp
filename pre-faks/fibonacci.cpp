#include <iostream>
#include <vector>

int elements;
int last = 1;
int temp;

int fibNumber(unsigned n);
int main(void){
	
	unsigned n;
	std:: cout << "Input how many elements of the Fibonacci sequence you want to get: ";
	std::cin >> n;
	/*
	JAVLJA SE SEFINA IZ 2024. GODINE DA POKAZE KAKO SE OVO RADI
	nums.push_back(1);
	nums.push_back(1);
	
	for (int i = 0; i < elements - 2; i++){
		int temp = nums.at(last) + nums.at(last - 1);
		nums.push_back(temp);
		last++;
	}
	
	for(int i = 0; i < elements; i++){
		cout << (i + 1);
		cout << " - ";
		cout << nums.at(i) << endl;
	}
	
	cout << "Insert anything to exit";
	cin >> temp;
	*/

	for (unsigned i = 0; i < n; i++) std::cout << fibNumber(i) << " ";
}
// 1 1 2 3 5 8
int fibNumber(unsigned n){
	static int memo[100] = {1, 1};
	if (n <= 0) return 0;
	if (memo[n]) return memo[n];
	return memo[n] = memo[n - 1] + memo[n - 2];
}