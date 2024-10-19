#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class VirtualPet{
	
	public:
		int hunger;
		int happiness;
		int fatigue;
	private:
		string type_string;
		string name;
		string ownerName;
		int type;
		
	public:		
	VirtualPet(string name_, int type_, string ownerName_){
		name = name_;
		type = type_;
		ownerName = ownerName_;
		
		switch(type){
			case 1:
				hunger = 60;
				happiness = 90;
				fatigue = 35;
				break;
			case 2:
				hunger = 90;
				happiness = 60;
				fatigue = 15;
				break;
			case 3:
				hunger = 95;
				happiness = 45;
				fatigue = 5;
				break;
		}
	}
	
	string getType(){
		
		switch(type){
			case 1:
				return "Pas";
				break;
			case 2:
				return "Macka";
				break;
			case 3:
				return "Kornjaca";
				break;
		}
	}	
	
	string getName(){
		return name;
	}
	
	string getOwnerName(){
		return ownerName;
	}
	
	void getStatus(){
		cout << "Hunger: " << hunger << endl;
		cout << "Happiness: " << happiness << endl;
		cout << "Fatigue: " << fatigue << endl;
		cout << endl;
	}
	
	void say(string sentence){
		cout << name << sentence << endl;
	}
	
};

void clearConsole(){
	for (int i = 0; i < 50; i++){
		cout << "" << endl;
	}
}

int main(){
	
	clearConsole();

	int choice;
	string name;
	string ownerName;
	
	cout << "Kako se zoves? ";
	cin >> ownerName;
	
	while (choice != 1 && choice != 2 && choice != 3){		
	cout << "Kakvog kucnog ljubimca zelis, " << ownerName << "?" << endl;
	cout << "" << endl;
	cout << "1. Psa" << endl;
	cout << "2. Macku" << endl;
	cout << "3. Kornjacu" << endl;
	cin >> choice;	
	}
	
	switch (choice){
		case 1:
			cout << "Kako zelis da nazoves svog psa? ";
			break;
		case 2:
			cout << "Kako zelis da nazoves svoju macku? ";
			break;
		case 3:
			cout << "Kako zelis da nazoves svoju kornjacu? ";
			break;
	}
	cin >> name;
	VirtualPet Pet(name, choice, ownerName);
	clearConsole();
	
	choice = 0;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
		
		cout << "## " << Pet.getType() << " " << Pet.getName() << " ##" << endl;
		cout << endl;
		
		cout << "1. Pricaj sa ljubimcem" << endl;
		cout << "2. Igraj se sa ljubimcem" << endl;
		cout << "3. Setaj ljubimca" << endl;
		cout << "4. Nahrani ljubimca" << endl;
		cout << "5. Stavi ljubimca na spavanje" << endl;
		
		cout << "Izbor: ";
		cin >> choice;
		
		switch (choice){
			case 1:
				
				Pet.happiness -= 3;
				Pet.fatigue += 5;
				Pet.hunger += 5;
				choice = 0;
				clearConsole();
				cout << "Zdravo ja sam " << Pet.getType() << " " << Pet.getName() << "! Moj vlasnik je " << Pet.getOwnerName() << "." << endl;
				
				if (Pet.happiness < 30){
					cout << "Trenutno sam veoma nesrecan >:(" << endl;
				}
				else if (Pet.happiness >= 30 && Pet.happiness < 60){
					cout << "Trenutno nisam bas najsrecniji." << endl;
				}
				else if (Pet.happiness >= 60 && Pet.happiness < 95){
					cout << "Trenutno sam srecan! :)" << endl;
				}
				else if (Pet.happiness >= 95){
					cout << "Trenutno sam bas bas srecan :D :D :D" << endl;
				}
				
				break;
			case 2:
				Pet.happiness += 12;
				Pet.fatigue += 15;
				Pet.hunger += 15;
				choice = 0;
				clearConsole();
				Pet.say("Wheeee!");
				break;
			case 3:
				Pet.fatigue += 12;
				Pet.hunger += 10;
				choice = 0;
				clearConsole();
				Pet.say("Mmmm svjez vazduh :)");
				break;
			case 4:
				Pet.fatigue += 5;
				Pet.hunger -= 20;
				choice = 0;
				clearConsole();
				Pet.say("Ukusna hrana. Mmmm...");
				break;
			case 5:
				Pet.fatigue -= 35;
				Pet.hunger += 25;
				Pet.happiness -= 12;
				choice = 0;
				clearConsole();
				Pet.say("Laku noc. Zzzz...");
				break; 
			case 1389:
				choice = 0;
				clearConsole();
				Pet.getStatus();
				break;
		}
	}
	
	return 0;
}
