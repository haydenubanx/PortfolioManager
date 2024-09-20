#pragma once
#include <iostream> 
#include <string> 
#include "Date.h"


//Security class as the base class for stocks and bonds
class security
{
	//Variable to store the date purchased
	Date purchaseDate;

	//Double to store the purchase price
	double purchasePrice;

	//Int to store the quantity purchased
	int quantityPurchased;

public:

	//Returns the purchase date
	Date getPurchaseDate() const;

	//Sets the purchase date to the input value
	void setPurchaseDate(Date inputDate);

	//Returns the purchase price
	double getPurchasePrice() const;


	//Sets the purchase price to the input value
	void setPurchasePrice(double inputPurchasePrice);

	//Returns the quantity purchased
	int getQuantityPurchased() const;

	//Sets the quantity purchased to the input value
	void setQuantityPurchased(int inputQuantityPurchased);


	//Defualt constructor
	security();


	//Destructor
	~security();
	

};