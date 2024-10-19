#include <iostream>
#include <string>
using namespace std;

struct Telefon{
	
	public:
	string brojTel = "123123123";
	int racunNovac = 10;
	
	Telefon(int racun, string broj){
		brojTel = broj;
		racunNovac = racun;
	}
	
	void zovi(string brojOsobe, int duzinaPoziva){
		if (racunNovac >= duzinaPoziva){
			racunNovac -= duzinaPoziva;
			cout << "Pozvan je broj " << brojOsobe << ", duzina trajanja poziva je " << duzinaPoziva << " minuta, sto je kostalo " << duzinaPoziva << "KM." << endl;
		}
		else{
			cout << "Nemas dovoljno na racunu da pozoves taj broj i razgovaras toliko dugo." << endl;
		}
	}
};

int main(){
	Telefon tel = Telefon(5, "066123456");
	
	tel.zovi("144144144", 5);
}
