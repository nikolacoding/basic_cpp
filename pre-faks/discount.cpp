#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dis(int originalPrice, int discount){
	double finalPrice;
	double ogPrice = originalPrice;
	double disc = discount;
	
	finalPrice = ogPrice - (ogPrice * disc / 100);
	
	int mainpart;
	int decimals;
	
	mainpart = trunc(finalPrice);
	decimals = trunc(finalPrice - mainpart * 100);
	decimals /= 100;
	
	finalPrice = mainpart + decimals;

	return finalPrice;
}

int main(){
	
	int a;
	int b;
	
	cin >> a;
	cin >> b;
	
	cout << dis(a, b);

	return 0;
}
