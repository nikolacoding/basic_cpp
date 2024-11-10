#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

class VirtualPet{
	public:
		int m_hunger;
		int m_happiness;
		int m_fatigue;
	private:
		std::string type;
		std::string name;
		std::string ownerName;
		int typeIndex;
		
	public:		
	VirtualPet(std::string name_, int type_, std::string ownerName_){
		name = name_;
		type = type_;
		ownerName = ownerName_;
		
		switch(typeIndex){
			case 1:
				m_hunger = 60;
				m_happiness = 90;
				m_fatigue = 35;
				break;
			case 2:
				m_hunger = 90;
				m_happiness = 60;
				m_fatigue = 15;
				break;
			case 3:
				m_hunger = 95;
				m_happiness = 45;
				m_fatigue = 5;
				break;
		}
	}
	
	std::string getType(){
		
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
	
	std::string getName(){
		return name;
	}
	
	std::string getOwnerName(){
		return ownerName;
	}
	
	void getStatus(){
		using namespace std;
		cout << "Hunger: " << m_hunger << endl;
		cout << "Happiness: " << m_happiness << endl;
		cout << "Fatigue: " << m_fatigue << endl;
		cout << endl;
	}
	
	void say(std::string sentence){
		std::cout << name << sentence << std::endl;
	}
	
};

void clearConsole(){
	for (int i = 0; i < 50; i++){
		std::cout << "" << std::endl;
	}
}

int main(){
	
	clearConsole();

	int choice;
	std::string name;
	std::string ownerName;
	
	std::cout << "Kako se zoves? ";
	std::cin >> ownerName;
	
	while (choice != 1 && choice != 2 && choice != 3){		
	std::cout << "Kakvog kucnog ljubimca zelis, " << ownerName << "?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1. Psa" << std::endl;
	std::cout << "2. Macku" << std::endl;
	std::cout << "3. Kornjacu" << std::endl;
	std::cin >> choice;	
	}
	
	switch (choice){
		case 1:
			std::cout << "Kako zelis da nazoves svog psa? ";
			break;
		case 2:
			std::cout << "Kako zelis da nazoves svoju macku? ";
			break;
		case 3:
			std::cout << "Kako zelis da nazoves svoju kornjacu? ";
			break;
	}
	std::cin >> name;
	VirtualPet Pet(name, choice, ownerName);
	clearConsole();
	
	choice = 0;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
		
		std::cout << "## " << Pet.getType() << " " << Pet.getName() << " ##" << std::endl;
		std::cout << std::endl;
		
		std::cout << "1. Pricaj sa ljubimcem" << std::endl;
		std::cout << "2. Igraj se sa ljubimcem" << std::endl;
		std::cout << "3. Setaj ljubimca" << std::endl;
		std::cout << "4. Nahrani ljubimca" << std::endl;
		std::cout << "5. Stavi ljubimca na spavanje" << std::endl;
		
		std::cout << "Izbor: ";
		std::cin >> choice;
		
		switch (choice){
			case 1:
				
				Pet.m_happiness -= 3;
				Pet.m_fatigue += 5;
				Pet.m_hunger += 5;
				choice = 0;
				clearConsole();
				std::cout << "Zdravo ja sam " << Pet.getType() << " " << Pet.getName() << "! Moj vlasnik je " << Pet.getOwnerName() << "." << std::endl;
				
				if (Pet.m_happiness < 30){
					std::cout << "Trenutno sam veoma nesrecan >:(" << std::endl;
				}
				else if (Pet.m_happiness >= 30 && Pet.m_happiness < 60){
					std::cout << "Trenutno nisam bas najsrecniji." << std::endl;
				}
				else if (Pet.m_happiness >= 60 && Pet.m_happiness < 95){
					std::cout << "Trenutno sam srecan! :)" << std::endl;
				}
				else if (Pet.m_happiness >= 95){
					std::cout << "Trenutno sam bas bas srecan :D :D :D" << std::endl;
				}
				
				break;
			case 2:
				Pet.m_happiness += 12;
				Pet.m_fatigue += 15;
				Pet.m_hunger += 15;
				choice = 0;
				clearConsole();
				Pet.say("Wheeee!");
				break;
			case 3:
				Pet.m_fatigue += 12;
				Pet.m_hunger += 10;
				choice = 0;
				clearConsole();
				Pet.say("Mmmm svjez vazduh :)");
				break;
			case 4:
				Pet.m_fatigue += 5;
				Pet.m_hunger -= 20;
				choice = 0;
				clearConsole();
				Pet.say("Ukusna hrana. Mmmm...");
				break;
			case 5:
				Pet.m_fatigue -= 35;
				Pet.m_hunger += 25;
				Pet.m_happiness -= 12;
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
