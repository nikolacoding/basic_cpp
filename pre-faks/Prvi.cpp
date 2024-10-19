#include <iostream>
#include <string>
using namespace std;

string choice = "";
string ime = "";

void print(string ispis)
{
	cout << ispis << endl;
}

int main()
{	
	while (choice != "0")
	{
		print("");
		print("Dobrodosli u program!");
		print("1. Unesi ime");
		print("2. Ispisi ime");
		print("");
		print("0. Napusti program");
		
		print("Unesi izbor: ");
		cin >> choice;
		
		if (choice == "1")
		{
			print("");
			print("Unesi ime: ");
			cin >> ime;
		}
		else if (choice == "2")
		{
			print("");
			print("Vase ime je " +  ime + ".");
		}
	}
	
	return 0;
}
