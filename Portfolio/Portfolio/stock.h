#pragma once
#include <iostream> 
#include <string> 
#include "security.h"



//Derived class from security of stocks
class stock : public security
{
	//Overloading of the < operator for comparing stocks based on their ticker Symbol alphabetically
	friend bool operator< (const stock&, const stock&);

	//String to store the ticker symbol
	std::string tickerSymbol;

	//Integer to store the par value
	int parValue;

	//Enum type of stocktypes for common or preferred stocks
	enum stockType { common, preferred };

	//Stocktype to store teh chosen stockType
	stockType currentStockType;

	//double to store teh dividends value
	double dividendsPerShare;

	//Int to store the number of shares
	int numberOfShares;

public:

	//Calculates the income (dividends per share * number of shares)
	double calcIncome() const;

	//Returns the ticker symbol
	std::string getTickerSymbol() const;

	//Sets the ticker symbol to the input value
	void setTickerSymbol(std::string inputTickerSymbol);

	//Returns the par value
	int getParValue() const;

	//Sets the par value to the input value
	void setParValue(int inputParValue);

	//Returns the currentStockType
	stockType getStockType() const;

	//sets the current stock type to the input value
	void setStockType(char inputStockType);
	
	//Returns teh dividends per share
	double getDividendsPerShare() const;

	//Sets the dividends per share to the input value
	void setDividendsPerShare(double inputDividends);

	//Function to return the number of shares bought in this stock
	int getNumberOfShares() const;

	//Sets the number of shares to the input number of shares
	void setNumberOfShares(int inputNumberOfShares);

	//default constructor, sets tickerSymbol to "" and all other values to 0
	stock();
	
	//Destructor
	~stock();



};