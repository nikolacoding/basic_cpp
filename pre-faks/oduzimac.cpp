#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

int dividend;
int dividendCurrent;
int divisor;

int main(){
	cout << "Unesi neki broj: ";
	cin >> dividend;
	dividendCurrent = dividend;
	
	cout << "Unesi djelilac tog broja: ";
	cin >> divisor;
	
	divisor = abs(divisor);

	if (dividend > 0){
		cout << dividend << "\n";
		while (dividendCurrent - divisor >= 0){
			dividendCurrent -= divisor;
			cout << dividendCurrent << "\n";
		}
	}
	else if (dividend < 0){
		cout << dividend << "\n";
		while (dividendCurrent - divisor <= 0){
			dividendCurrent += divisor;
			cout << dividendCurrent << "\n";
		}
	}
	
	return 0;
}
