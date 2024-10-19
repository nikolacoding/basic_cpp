#include <iostream>

// 1 car = 2 wheels, 1 body, 2 figures

int cars(int wheels, int bodies, int figures){
	
	const int reqWheels = 4;
	const int reqBodies = 1;
	const int reqFigures = 2;
	
	int currWheels, currBodies, currFigures;
	int carCount = 0;
	
	currWheels = wheels;
	currBodies = bodies;
	currFigures = figures;
	
	while (currWheels >= reqWheels && currBodies >= reqBodies && currFigures >= reqFigures){
		
		currWheels -= reqWheels;
		currBodies -= reqBodies;
		currFigures -= reqFigures;
		
		carCount++;
	}
	
	return carCount;
}

int main(){
	
	int wh, bo, fi;
	
	std::cin >> wh;
	std::cin >> bo;
	std::cin >> fi;
	std::cout << cars(wh, bo, fi);
}
