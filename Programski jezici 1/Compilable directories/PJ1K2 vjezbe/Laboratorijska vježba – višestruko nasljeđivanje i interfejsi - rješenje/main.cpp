#include <iostream>
#include "Item.h"
#include "Pen.h"
#include "Book.h"
#include "Sale.h"
#include "FinancialReport.h"
#include "SaleItem.h"
#include "Discount.h"
#include "DiscountSpecial.h"

int main()
{	
	Sale* sale1 = new Sale;
	sale1->addItem(new SaleItem(Pen("Pen1", 50), 3));
	sale1->addItem(new SaleItem(Pen("Pen2", 75), 5));
	sale1->addItem(new SaleItem(Book("1984", 1000, "George Orwell", "9780451524935"), 7));
	sale1->addItem(new SaleItem(Book("Dune", 1000, "Frank Herbert", "9780441172719"), 10));
	// std::cout << *sale1 << std::endl;

	Sale* sale2 = new Sale;
	sale2->addItem(new Pen("Pen3", 25));
	sale2->addItem(new Pen("Pen4", 25));
	sale2->addItem(new Book("The Man Who Was Thursday", 1000, "G. K. Chesterton", "9780486251219"));
	sale2->addItem(new Book("Charlotte's Web", 1000, "Elwyn Brooks White", "9780064410939"));
	// std::cout << *sale2 << std::endl;

	Sale* sale3 = (Sale*) sale2->clone();
	Sale* sale4 = new Discount(*sale1, 0.1); // 10% discount
	Sale* sale5 = new DiscountSpecial(*sale4, 0.2); // 20% more in case there are more than 3 items in the cart

	FinancialReport report;
	report.addSale(sale1);
	report.addSale(sale4);
	report.addSale(sale3);
	report.addSale(sale5);
	std::cout << report << std::endl;
	return 0;
}