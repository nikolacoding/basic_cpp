#include <iostream>
#include <vector>

bool simonSays(std::vector<int> firstArray, std::vector<int> secondArray){
	if (firstArray.size() != secondArray.size())
	{
		return false;
	}
}

int main(){
	
	std::cout << simonSays([1, 2], [3, 4]);
	return 0;
}
