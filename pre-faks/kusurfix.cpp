#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;

int balance;
int price;
int kusur;

bool ended = false;

int main(void){
	
	const std::vector<int> apoeni = {50, 10, 5, 2, 1};
	const std::string valuta = "KM";
	cout << "Unesi novac i cijenu proizvoda: " << endl;
	cin >> balance >> price;
	kusur = balance - price;

	auto iterator = [](int& ret, int ap) -> int {
		int uk = 0;
		while (ret >= ap){
			ret -= ap;
			uk++;
		}
		return uk; 
	};
	
	if (!kusur) cout << "Kupio si proizvod sa tacno dovoljno novca." << endl;
	else if (kusur < 0) cout << "Nedostaje ti " << -kusur << "KM." << endl;
	else{
		int total = 0;
		for (int a : apoeni){
			int curr = iterator(kusur, a);
			total += curr * a;
			if (curr)
				cout << std::to_string(a) << valuta << ": " << std::to_string(curr) << endl;
		}
		cout << "Ukupno: " << std::to_string(total) << endl;
	}
		
	return 0;
}
