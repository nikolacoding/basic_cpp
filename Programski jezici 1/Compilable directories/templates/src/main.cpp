#include <iostream>
using std::cout;
using std::printf;
using std::cin;

#include "OSIK1.hpp"

void printMenu(){
    printf("Izaberi opciju:\n");
    printf("   1. Pokreni pitalicu\n");
    printf("   2. Ispisi sva pitanja\n");
    printf("   3. Dodaj pitanje\n");
}

int main(void)
{
    int choice;
    while (true){
        printMenu();
        cin >> choice;
    }
}