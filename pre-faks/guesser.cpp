#include <iostream>
#include <string>
#include <time.h>

// sefina iz 2024. je ovdje da ovo ispravi

using std::cout;
using std::cin;
using std::endl;
int main(){
	constexpr int starting_attempts = 10;
	int num, attempts = starting_attempts, guess;
	srand(time(0));
	num = (rand() % 50) + 1;
	
	while (attempts){
		cout << "Pogodi: "; cin >> guess;
		if (guess == num){
			cout << "Pogodak! Zamisljeni broj je " << num << "!" << endl;
			break;
		}
		else if (guess > num) cout << "Broj je manji.";
		else if (guess < num) cout << "Broj je veci.";
		cout << endl;
		attempts--;
	}
	if (!attempts) cout << "Nisi pogodio iz " << starting_attempts << " pokusaja." << endl;

	return 0;
}
