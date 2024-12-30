#include <iostream>

#include "Pen.hpp"
#include "Book.hpp"
#include "Sale.hpp"

int main(void){
    Item* pen1 = new Pen(0.75, "Grafitna olovka");
    Item* pen2 = new Pen(2, "Hemijska olovka");
    Item* pen3 = new Pen(14, "Profesionalna olovka");

    Item* book1 = new Book(1.50, "Djecija sveska");
    Item* book2 = new Book(12, "Zbirka matematike");
    Item* book3 = new Book(120, "ASOIAF kolekcija");

    Sale sale;
    sale.append(pen1);
}