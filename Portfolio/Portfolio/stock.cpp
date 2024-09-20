#include <iostream> 
#include <string> 
#include <algorithm>
#include "stock.h"
using namespace std;


//Overloads the < operator to compare stocks by ticker symbol
bool operator< (const stock& inputStock, const stock& compareStock)
{
	//Bool to track if lefthand ticker symbol is less than righthand ticker sybmol
	bool isLessThan = false;

	//Compares left and righthand i=tickersymbols
	if (inputStock.getTickerSymbol() < compareStock.getTickerSymbol())
	{
		//sets bool to true if lefthand is less than righthand
		isLessThan = true;
	}

	//Returns boolean expression
	return isLessThan;
}

	//Calculates the income for teh stock (dividends per share * number of shares)
	double stock::calcIncome() const
	{
		//Sets the income equal to the calculated formula
		double income = (getDividendsPerShare() * getQuantityPurchased());

		//returns teh calculated value
		return income;
	}

	//Returns the ticker symbol
	string stock::getTickerSymbol() const
	{
		return tickerSymbol;
	}

	//Sets the ticker symbol to the input value
	void stock::setTickerSymbol(string inputTickerSymbol)
	{
		tickerSymbol = inputTickerSymbol;
	}

	//Returns the par value
	int stock::getParValue() const
	{
		return parValue;
	}

	//Sets the par value to the input value
	void stock::setParValue(int inputParValue)
	{
		parValue = inputParValue;
	}

	//Returns the stock type
	stock::stockType stock::getStockType() const
	{
		return  currentStockType;
	}

	//Sets the stock type to the input value 
	void stock::setStockType(char inputStockType)
	{
		//If the passed instruction is C then stockType is set to common
		if (inputStockType == 'C')
		{
			//Common is 0 or teh first value in the enum type
			currentStockType = stockType(0);
		}

		//If the passed instruction is P the stock Type is set to preferred
		else if (inputStockType == 'P')
		{
			//Preferred is 1 or the second value in the enum type
			currentStockType = stockType(1);
		}
	}

	//Returns the dividends per share 
	double stock::getDividendsPerShare() const
	{
		return dividendsPerShare;
	}

	//Sets teh dividends to teh input value
	void stock::setDividendsPerShare(double inputDividends)
	{
		dividendsPerShare = inputDividends;
	}


	//Function to return the number of shares bought in this stock
	int stock::getNumberOfShares() const
	{
		return getQuantityPurchased();
	}


	//Sets the number of shares to the input number of shares
	void stock::setNumberOfShares(int inputNumberOfShares)
	{
		numberOfShares = inputNumberOfShares;
	}


	//default constructor, sets tickerSymbol to "" and all other values to 0
	stock::stock()
	{
		setPurchasePrice(0);
		setQuantityPurchased(0);
		tickerSymbol = "";
		parValue = 0;
		dividendsPerShare = 0;
		numberOfShares = 0;
	}

	//Destructor
	stock::~stock()
	{

	}


