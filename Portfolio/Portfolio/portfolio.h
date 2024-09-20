#pragma once
#include <iostream> 
#include <string> 
#include <vector>
#include "stock.h"
#include "bond.h"




class portfolio
{

	//Overloading of the << operator to print the stock info
	friend std::ostream& operator<< (std::ostream& outputType, const stock& thisStock);


	//Overloading of the << operator to print the bond info
	friend std::ostream& operator<< (std::ostream& outputType, const bond& thisBond);




	std::string name;
	std::vector<stock> ownedStocks;
	std::vector<bond> ownedBonds;



public:

	//Calls funtion to create and add a stock to the vector
	void purchaseStocks();

	//Function that runs to purchase Bonds
	void purchaseBonds();

	//Prints all of the stocks and bonds in the portfolio
	void listPortfolio();

	void setName(std::string inputName);

	std::string getName() const;
	
	//Returns the number of stocks in the ownedStocks vector
	int getNumberOfStocks() const;

	//Returns the number of bonds in the ownedBonds vector
	int getNumberOfBonds() const;

	

	//Function to return a stock at the given index in the vector
	stock getStock(int index) const;
	
	//Tokenize the date to sort it into the correct format
	void tokenizeDate(char* cDate, int& month, int& day, int& year);


	void sortStockVector(std::vector<stock> &stockVector);

	void sortBondVector(std::vector<bond> &bondVector);


	//constructors

	//Default
	portfolio();
	

	//initializes name
	portfolio(std::string inputName);


	

	//Destructor
	~portfolio();

};