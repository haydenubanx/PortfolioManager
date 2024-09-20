#pragma once
#include <iostream> 
#include <string> 
#include "security.h"


	//Returns the purchase date
	Date security::getPurchaseDate() const
	{
		return purchaseDate;
	}

	//Sets the purchase date to the input value
	void security::setPurchaseDate(Date inputDate)
	{
		purchaseDate = inputDate;
	}

	//Returns the purchase price
	double security::getPurchasePrice() const
	{
		return purchasePrice;
	}

	//sets the purchase price to the input value
	void security::setPurchasePrice(double inputPurchasePrice)
	{
		purchasePrice = inputPurchasePrice;
	}

	//Returns the quantity purchased
	int security::getQuantityPurchased() const
	{
		return quantityPurchased;
	}

	//Sets the quantity purchased to the input value
	void security::setQuantityPurchased(int inputQuantityPurchased)
	{
		quantityPurchased = inputQuantityPurchased;
	}

	//Defualt constructor
	security::security()
	{
		purchasePrice = 0;

		quantityPurchased = 0;
	}

	//Destructor
	security::~security()
	{

	}