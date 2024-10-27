#include "Array.h"
#include <iostream>
using PJ1Lab::Array;

// konstruktor; 
// svaka instanca Arraya se inicijalizuje sa: 
// 1) capacity: ILI korisnicki definisanim kapacitetom ILI podrazumijevanom vrijednoscu 
//          definisanom u Array.h (1)
// 2) isize (privatna velicina niza shodno trenutno definisanim elementima) = 0
// 3) array: pokazivac na prvi clan (double) dinamickog niza - alocira se prostor za jedan element
Array::Array(int capacity) : capacity(capacity), isize(0), array(new double[capacity]) {}

// destruktor; poziva metodu void dispose() koja dealocira ovaj ^ dinamicki niz
Array::~Array(){
    dispose();
}

// geter trenutne velicine niza
int Array::size() const{
    return this->isize;
}

   
void Array::append(double value){
// dodavanje elementa na kraj niza u skladu sa trenutnom velicinom i ukupnim kapacitetom
    if (this->isize < capacity){
        this->array[this->isize++] = value;
    }
// velicina (i kapacitet u edge case-u) prednjace indeksu posljednjeg elementa za 1
}

bool Array::insertAt(int index, double value){
// provjeravamo da li je u funkciju poslat validan indeks (broj iz Z+ u okviru trenutne velicine niza)
    if (index < this->isize && index >= 0){
// pa, ukoliko jeste, unosimo poslatu vrijednost na dati indeks ukoliko jeste, vracajuci true (uspjesno)
        this->array[index] = value;
        return true;
    }
// u suprotnom vracamo false (neuspjesno)
    return false;
}

bool Array::removeAt(int index){
// provjeravamo da li je u funkciju poslat validan indeks (broj iz Z+ u okviru trenutne velicine niza)
    if (index < this->isize && index >= 0){
// pa, ukoliko jeste, postavljamo vrijednost clana niza na koji indeks pokazuje na nula, vracajuci true
        this->array[index] = 0;
        return true;
    }
// u suprotnom vracamo false
    return false;
}

// overload (1)
double& Array::at(int index, bool& success) const {
// provjeravamo da li je u funkciju poslat validan indeks (broj iz Z+ u okviru trenutne velicine niza)
    if (index < this->isize && index >= 0){
// pa, ukoliko jeste, referencirani parametar bool za provjeru statusa postavljamo na true
        success = true;
// i vracamo referencu na clan na koji pokazuje poslati indeks
        return this->array[index];
    }
// u suprotnom ref. p. bool postavljamo na false, oznacavajuci neuspjesan pronalazak ili nevalidan pokusaj
    success = false;
}

// overload (2)
double& Array::at(int index) const {
// provjeravamo da li je u funkciju poslat validan indeks (broj iz Z+ u okviru trenutne velicine niza)
    if (index < this->isize && index >= 0){
// pa, ukoliko jeste, ispisujemo adekvatnu poruku na stdout
        std::cout << "Validan element pronadjen na indeksu " << index 
        << ": " << this->array[index] << std::endl;
// i vracamo referencu na clan na koji pokazuje poslati indeks
        return this->array[index];
    }
// u suprotnom, ispisujemo adekvatnu poruku na stdout oznacavajuci neuspjesan pronalazak ili nevalidan pokusaj
    std::cout << "Neuspjesan pronalazak elementa na indeksu " << index << "!" << std::endl;
}

void Array::dispose(){
// dealokacija dinamicki alociranog niza array u sklopu instance datog objekta (this)
// - metoda se direktno poziva u destruktoru
    delete[] this->array;
}