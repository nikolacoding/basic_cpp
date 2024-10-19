#include <iostream>

using namespace std;

int a10, a5, a2, a1 = 0;

int bal;
int price;
int kusur;

bool ended = false;

int main(){
	
	cout << "Unesi novac i cijenu proizvoda: " << endl;
	
	cout << "Unesi novac: ";
	cin >> bal;
	
	cout << "Unesi cijenu proizvoda: ";
	cin >> price;

	kusur = bal - price;
	
	if (kusur < 0){
		cout << "Nemas novoljno novca da kupis proizvod. Nedostaje ti ";
		cout << -kusur;
		cout << "KM.";
	}
	else if (kusur == 0){
		cout << "Kupio si proizvod i nemas kusura." << endl;
	}
	else{
		
		a10 += kusur / 10;
		kusur -= a10 * 10;
		
		a5 += kusur / 5;
		kusur -= a5 * 5;
		
		a2 += kusur / 2;
		kusur -= a2 * 2;
		
		a1 += kusur;
		kusur -= a2;
		
		cout << "Kupio si proizvod, i kusur koji si dobio je sledeci: " << endl;
		
		if (a10 != 0){
			cout << a10;
			cout << " novcanica od 10KM";
		}
		
		if (a5 != 0){
			if (a10 != 0){
				cout << ", ";
			}
			cout << a5;
			cout << " novcanica od 5KM";
		}
		
		if (a2 != 0){
			cout << ", ";
			cout << a2;
			cout << " novcanica od 2KM";
		}
		
		if (a1 != 0){
			cout << ", ";
			cout << a1;
			cout << " novcanica od 1KM";
		}
		
		cout << "." << endl;
	}
		
	return 0;
}
