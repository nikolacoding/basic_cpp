#include <iostream>
#include "Array.h"

Array f(){
    Array a;
    a.append(99);
    return a;
}

int main(void){
    Array a1;
    Array a2(3);

    a1.append(4); a1.append(5); a1.append(6); a1.append(7);
    a2.append(4); a2.append(5); a2.append(6); a2.append(7);

    a1.write();
    a2.write();

    Array a3 = f();
    //         ^ konstruktor pomjeranja je pozvan jer je f() nista drugo nego rvalue uhvacen
    // preklapanjem konstruktora koji njega uzima kao argument (Array&&)

    // napomena: u tasks.json je dodan flag "-fno-elide-constructors" koji omogucava pravilnu
    // invokaciju/pozivanje konstruktura pomjeranja jer moderni C++ standardi vrse copy-elision
    // optimizaciju, uklonivsi potrebu za k.p. u ovom konkretnom primjeru

    Array a4(5, 6);
    //       ^ delegirajuci konstruktor, poziva se Array(5);

    // napomena: indeksiranje je neispravno

    a3.write();
    a4.write();
}