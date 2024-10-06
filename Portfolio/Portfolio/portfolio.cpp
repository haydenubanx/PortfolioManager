#include <iostream> 
#include <string> 
#include <iomanip>
#include <cstring>
#include "portfolio.h"
using namespace std;




	//Overloading of the << operator to print the stock info
	ostream& operator<< (ostream& outputType, const stock& thisStock)
	{
		//Print Statements for stock variables
		outputType << left << setw(30) << "Ticker Symbol: " << thisStock.getTickerSymbol() << endl;
		outputType << left << setw(30) << "Purchase Date: " << thisStock.getPurchaseDate() << endl;
		outputType << left << setw(30) << "Purchase Price: " << "$" << thisStock.getPurchasePrice() << endl;
		outputType << left << setw(30) << "Quantity Purchased: " << thisStock.getQuantityPurchased() << endl;
		outputType << left << setw(30) << "Par Value: " << "$" << thisStock.getParValue() << endl;

		//If the stockType is 0 it is the irst enumeration type of common
		if (thisStock.getStockType() == 0)
		{
			outputType << left << setw(30) << "Stock Type: " << "Common" << endl;
		}

		//Otherwise it is teh second numeration type of preferred
		else
		{
			outputType << left << setw(30) << "Stock Type: " << "Preferred" << endl;
		}

		//Remaining print statements
		outputType << left << setw(30) << "Dividends Per Share: " << "$" << thisStock.getDividendsPerShare() << endl;
		outputType << left << setw(30) << "Dividends Income: " << "$" << thisStock.calcIncome() << endl << endl;

		//Returns the output type 
		return outputType;
	}


	//Overloading of the << operator to print the bond info
	ostream& operator<< (ostream& outputType, const bond& thisBond)
	{
		//Print Statements for bond variables
		outputType << left << setw(30) << "Issuer: " << thisBond.getIssuer() << endl;
		outputType << left << setw(30) << "Purchase Date: " << thisBond.getPurchaseDate() << endl;
		outputType << left << setw(30) << "Purchase Price: " << "$" << thisBond.getPurchasePrice() << endl;
		outputType << left << setw(30) << "Quantity Purchased: " << thisBond.getQuantityPurchased() << endl;
		outputType << left << setw(30) << "Face Value: " << "$" << thisBond.getFaceValue() << endl;
		outputType << left << setw(30) << "Stated Interest Rate: " << (thisBond.getStatedInterestRate() * 100)
			<< "%" << endl;
		outputType << left << setw(30) << "Maturity Date: " << thisBond.getMaturityDate() << endl;
		outputType << left << setw(30) << "Interest Income: " << "$" << thisBond.calcIncome() << endl << endl;

		//returns stream output type
		return outputType;
	}




	//Function to add a stock to the vector of stocks
	void portfolio::purchaseStocks()
	{
		//Creates new stock object
		stock newStock;

		//Declares variables to store the month, day, and year
		int m, d, y;

		//temporary variables to pass these items into the stock class
		//
		//variable to temprorarily store the entered purchase price for error checking
		double tempPurchasePrice;

		//variable to temprorarily store the entered quantity purchased for error checking
		int tempQuantityPurchased;

		//variable to temprorarily store the entered ticker Symbol for error checking
		string tempTickerSymbol;

		//variable to temprorarily store the entered par value for error checking
		int tempParValue;

		//variable to temprorarily store the entered stock type for error checking
		char tempStockType;

		//variable to store the dividends per share for error checking
		double tempDividendsPerShare;

		//bool variable to hold if the date has been formatted correctly
		bool dateFormattedCorrectly;



		//holds the date the user entered in char array
		char charDate[20];


		//date object; holds date after tokenization
		Date realDate;

		//Prompts user for input date
		cout << "Purchase Date (mm/dd/yyyy): ";
		cin >> charDate;
		cout << endl << endl;

		//If the second and fifth characters are not backslashes, then the date was formatted incorectly
		if (charDate[2] != '/' || charDate[5] != '/')
		{
			//Sets the date format boolean expression to false 
			dateFormattedCorrectly = false;
		}

		//Otherwise teh date is formatted correctly and the boolean is set to true
		else
		{
			dateFormattedCorrectly = true;
		}

		//If the date has been formatted correctly the date is tokenized and reformatted
		if (dateFormattedCorrectly == true)
		{
			//separates char array into month, day, and year
			tokenizeDate(charDate, m, d, y);
			//sets the date of the object using the parsed values
			realDate.setDate(d, m, y);
		}
	


		//Error Checking: if the day is less than 0 or over 31 it is impossible and incorrect, likewise
		//if the month is less than zero or greater than 12 it is incorrect
		//This error catch is also triggered if the date was formatted incorrectly
		while (cin.fail() || realDate.getDay() <= 0 || realDate.getDay() > 31 || realDate.getMonth() <= 0 || 
			realDate.getMonth() > 12 || dateFormattedCorrectly == false)
		{
			//Prompts the user to reenter the date with correct formatting
			cout << "Date entered incorrectly. Please check date enterd and try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Purchase Date (mm/dd/yyyy): ";
			cin >> charDate;
			cout << endl << endl;

			//Same error checking as above for formatting
			if (charDate[2] != '/' || charDate[5] != '/')
			{
				dateFormattedCorrectly = false;
			}
			else
			{
				dateFormattedCorrectly = true;
			}


			//separates char array into month, day, and year
			tokenizeDate(charDate, m, d, y);
			//sets the date of the object using the parsed values
			realDate.setDate(d, m, y);
		}



		//Sets this stock's purchase date to the tokenized & formatted date in realDate
		newStock.setPurchaseDate(realDate);


		//Prompts the user for the total purchase price
		cout << "Total Purchase Price: " << "$";
		cin >> tempPurchasePrice;
		cout << endl << endl;

		//Error Checking: purchase price must be positive numbers
		while (cin.fail() || tempPurchasePrice < 0)
		{
			cout << "You must enter a positive number. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Total Purchase Price: " << "$";
			cin >> tempPurchasePrice;
			cout << endl << endl;
		}


		//Sets the purchase price for the stock to the entered purchase Price
		newStock.setPurchasePrice(tempPurchasePrice);


		//Prompts the user for the quantity purchased
		cout << "Quantity Purchased: ";
		cin >> tempQuantityPurchased;
		cout << endl << endl;

		//Error Checking: quantity values must be positive integers
		while (cin.fail() || tempQuantityPurchased < 0)
		{
			cout << "You must enter a positive number. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Quantity Purchased: ";
			cin >> tempQuantityPurchased;
			cout << endl << endl;
		}

		//Sets the quantity purchased for the stock to the entered quantity
		newStock.setQuantityPurchased(tempQuantityPurchased);


		//Prompts the user for the ticker symbol
		cout << "Ticker Symbol: ";
		cin >> tempTickerSymbol;
		cout << endl << endl;

		//Bool to track if all the characters are alphabetic
		bool allAlphabetic = true;

		//Loops through each character
		for (int i = 0; i < tempTickerSymbol.size(); i++)
		{
			//If this character is not an alphabetic character
			if (isalpha(tempTickerSymbol[i]) == 0)
			{
				//Set bool allAlphabetic to false
				allAlphabetic = false;

				//Break from for loop since error has been found
				break;
			}
		}

			//Error Checking: If not all of the characters are alphabetic
			while (cin.fail() || allAlphabetic == false)
			{
				cout << "Ticker Symbols consist of a string of alphabetic characters. Please try again. " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Ticker Symbol: ";
				cin >> tempTickerSymbol;
				cout << endl << endl;

				//Same error checking as above, loops through all characters to check for non
				//alphabetic characters
				for (int i = 0; i < tempTickerSymbol.size(); i++)
				{
					if (isalpha(tempTickerSymbol[i]) == 0)
					{
						allAlphabetic = false;

						break;
					}
					else
					{
						allAlphabetic = true;
					}
				}

			}



		//Sets the Ticker Symbol of the stock to the entered ticker symbol
		newStock.setTickerSymbol(tempTickerSymbol);


		//Prompts the user for the par value
		cout << "Par Value: " << "$";
		cin >> tempParValue;
		cout << endl << endl;

		//Error Checking: must be a positive integer
		while (cin.fail() || tempParValue < 0)
		{
			cout << "You must enter a positive number. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Par Value: " << "$";
			cin >> tempParValue;
			cout << endl << endl;
		}

		//Sets the par value of the stock to the entered par value
		newStock.setParValue(tempParValue);


		//Prompts the user for the stocktype
		cout << "Stock Type (C for Common or P for Preferred): ";
		cin >> tempStockType;
		//Sets the stockType to uppercase
		tempStockType = toupper(tempStockType);
		cout << endl << endl;

		//Error Checking: Must be capital 'C' or 'P'
		while (cin.fail() || (tempStockType != 'C' && tempStockType != 'P'))
		{
			cout << "You must enter either the character C for Common or P for Preferred. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Stock Type (C for Common or P for Preferred): ";
			cin >> tempStockType;
			cout << endl << endl;
		}

		//Passes the stock type to the function to set the stock type
		newStock.setStockType(tempStockType);

		//Prompts the user for the dividends per share
		cout << "Dividends Per Share: " << "$";
		cin >> tempDividendsPerShare;
		cout << endl << endl;

		//Error Checking: Must be positive number
		while (cin.fail() || tempDividendsPerShare < 0)
		{
			cout << "You must enter a positive numeric value. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Dividends Per Share: " << "$";
			cin >> tempDividendsPerShare;
			cout << endl << endl;
		}

		//Passes the instruction type to the function to set the stock type
		newStock.setDividendsPerShare(tempDividendsPerShare);


		//Adds stock to the vector of stocks
		ownedStocks.push_back(newStock);

	}



	//Function that runs to purchase Bonds
	void portfolio::purchaseBonds()
	{
		//Creates a pointer to a new stock item to be passed into the stock vector
		bond newBond;

		//Declares variables to store the month, day, and year
		int m, d, y;

		//temporary variables to pass these items into the stock class
		//
		//variable to store the entered purchase price for error checking
		double tempPurchasePrice;

		//variable to store the quantity for error checking
		int tempQuantityPurchased;

		//string to store teh issuer for error checking
		string tempIssuer;

		//variable to store the face value for error checking
		int tempFaceValue;

		//variable to store the interest rate for error checking
		double tempStatedInterestRate;

		//variable to store the maturity date for error checking
		Date tempMaturityDate;

		//boolean to sore if the date has been formatter correctly
		bool dateFormattedCorrectly;



		//holds the date the user entered in char array
		char charDate[20];

		//date object; holds date after tokenization
		Date realDate;

		//Prompts the user for the purchase date
		cout << "Purchase Date (mm/dd/yyyy): ";
		cin >> charDate;
		cout << endl << endl;

		//Error Checking: if the 2nd and 5th characters are not '/' then the date was formatted incorrectly
		if (charDate[2] != '/' || charDate[5] != '/')
		{
			//Set boolean to check if correctly formatted to false
			dateFormattedCorrectly = false;
		}

		//Otherwise set the boolean to true
		else
		{
			dateFormattedCorrectly = true;
		}

		//If the date was formatted correctly
		if (dateFormattedCorrectly == true)
		{
			//separate char array into month, day, and year
			tokenizeDate(charDate, m, d, y);
			//set the date of the object using the parsed values
			realDate.setDate(d, m, y);
		}



		//Error Checking: Checks dates are within real ranges and that date was formatted correctly
		while (cin.fail() || realDate.getDay() <= 0 || realDate.getDay() > 31 || realDate.getMonth() <= 0 ||
			realDate.getMonth() > 12 || dateFormattedCorrectly == false)
		{
			cout << "Date entered incorrectly. Please check date enterd and try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Purchase Date (mm/dd/yyyy): ";
			cin >> charDate;
			cout << endl << endl;

			//Same error checking as above for formatting
			if (charDate[2] != '/' || charDate[5] != '/')
			{
				dateFormattedCorrectly = false;
			}
			else
			{
				dateFormattedCorrectly = true;
			}


			//separates char array into month, day, and year
			tokenizeDate(charDate, m, d, y);
			//sets the date of the object using the parsed values
			realDate.setDate(d, m, y);
		}

		//Sets this Bond's purchase date to the tokenized & formatted date in realDate
		newBond.setPurchaseDate(realDate);


		//Prompts the user for the total purchase price
		cout << "Total Purchase Price: " << "$";
		cin >> tempPurchasePrice;
		cout << endl << endl;

		//Error Checking: purchase price must be a positive number
		while (cin.fail() || tempPurchasePrice < 0)
		{
			cout << "You must enter a positive numeric value. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Total Purchase Price: " << "$";
			cin >> tempPurchasePrice;
			cout << endl << endl;
		}

		//Sets the purchase price for the stock to the entered purchase Price
		newBond.setPurchasePrice(tempPurchasePrice);

		//Prompts the user for the quantity purchased
		cout << "Quantity Purchased: ";
		cin >> tempQuantityPurchased;
		cout << endl << endl;

		//Error Checking: the quantity purchased must be a positive number
		while (cin.fail() || tempQuantityPurchased < 0)
		{
			cout << "You must enter a positive numeric value. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Quantity Purchased: ";
			cin >> tempQuantityPurchased;
			cout << endl << endl;
		}

		//Sets the quantity purchased for the stock to the entered quantity
		newBond.setQuantityPurchased(tempQuantityPurchased);

		//Prompts the user for the issuer
		cout << "Issuer: ";
		cin >> tempIssuer;
		cout << endl << endl;

	
		//Bool to track if all the characters are alphabetic
		bool allAlphabetic = true;
		

		//Loops through each character to see if all characters are alphabetic
		for (int i = 0; i < tempIssuer.size(); i++)
		{
			//If the character is not alphabetic
			if (isalpha(tempIssuer[i]) == 0)
			{
				//Set boolean to false
				allAlphabetic = false;

				//break from loop since error has been found
				break;
			}
		}

		//Error Checking: All characters must be alphabetic
		while (cin.fail() || allAlphabetic == false)
		{
			cout << "Name of Issuer must contain alphabetic characters only. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Issuer: ";
			cin >> tempIssuer;
			cout << endl << endl;

			//Same error checking on characters as above
			for (int i = 0; i < tempIssuer.size(); i++)
			{
				if (isalpha(tempIssuer[i]) == 0)
				{
					allAlphabetic = false;

					break;
				}
				else
				{
					allAlphabetic = true;
				}
			}

		}


		//Sets the Ticker Symbol of the stock to the entered ticker symbol
		newBond.setIssuer(tempIssuer);


		//Prompts teh user for the face value
		cout << "Face Value: " << "$";
		cin >> tempFaceValue;
		cout << endl << endl;

		//Error Checking: face value must be positive numeric value
		while (cin.fail() || tempFaceValue < 0)
		{
			cout << "You must enter a positive numeric value. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Face Value: " << "$";
			cin >> tempFaceValue;
			cout << endl << endl;
		}

		//Sets the par value of the stock to the entered par value
		newBond.setFaceValue(tempFaceValue);

		//Prompts teh user for teh interest rate
		cout << "Stated Interest Rate: ";
		cin >> tempStatedInterestRate;
		cout << endl << endl;

		//Error Checking: must be positive number
		while (cin.fail() || tempStatedInterestRate < 0)
		{
			cout << "Interest rate must be a positive number in decimal format. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Stated Interest Rate: ";
			cin >> tempStatedInterestRate;
			cout << endl << endl;
		}

		//Passes the Interest rate to the function to set the interest rate
		newBond.setStatedInterestRate(tempStatedInterestRate);



		//Prompts teh user for the Maturity Date
		cout << "Maturity Date (mm/dd/yyyy): ";
		cin >> charDate;
		cout << endl << endl;

		//Error Checking: Same as on other dates, if the 2nd or 5th characters are not '/' then the date was
		//formatted incorrectly
		if (charDate[2] != '/' || charDate[5] != '/')
		{
			dateFormattedCorrectly = false;
		}
		else
		{
			dateFormattedCorrectly = true;
		}

		if (dateFormattedCorrectly == true)
		{
			//separates char array into month, day, and year
			tokenizeDate(charDate, m, d, y);
			//sets the date of the object using the parsed values
			realDate.setDate(d, m, y);
		}



		//Error Checking: if date values out of range or date was formatted incorrectly
		while (cin.fail() || realDate.getDay() <= 0 || realDate.getDay() > 31 || realDate.getMonth() <= 0 ||
			realDate.getMonth() > 12 || dateFormattedCorrectly == false)
		{
			cout << "Date entered incorrectly. Please check date enterd and try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Maturity Date (mm/dd/yyyy): ";
			cin >> charDate;
			cout << endl << endl;

			//Same error checking as above for date formatting
			if (charDate[2] != '/' || charDate[5] != '/')
			{
				dateFormattedCorrectly = false;
			}
			else
			{
				dateFormattedCorrectly = true;
			}


			//separates char array into month, day, and year
			tokenizeDate(charDate, m, d, y);
			//sets the date of the object using the parsed values
			realDate.setDate(d, m, y);
		}

		//Sets this Bond's maturity date to the tokenized & formatted date in realDate
		newBond.setMaturityDate(realDate);


		//Adds Bond to the vector of bonds
		ownedBonds.push_back(newBond);
	}

	//Function to print all of the stock and bond values in teh portfolio
	void portfolio::listPortfolio()
	{
		//Print statement for stock heading
		cout << "The stocks in your " << getName() << " portfoio:\n";

		//Cycles over each stock and prints it out
		for (int i = 0; i < getNumberOfStocks(); i++)
		{
			//Sorts the vector of stocks
			sortStockVector(ownedStocks);

			//creates stock object for the stock being currently cycled over
			stock newStock = getStock(i);

			//Prints this stock
			cout << newStock << endl << endl;

		}


	
		//Print statement for bond heading
		cout << "The bonds in your " << getName() << " portfoio:\n";

		//Cycles over Each Bond and prints it out
		for (int i = 0; i < getNumberOfBonds(); i++)
		{
			//Sorts the bond vector
			sortBondVector(ownedBonds);

			//Creates new bond object for bond being currently itterated over
			bond newBond = ownedBonds.at(i);


			//Prints this bond
			cout << newBond << endl << endl;
		}

	}

	//Function to return the number of stocks in the stock vector
	int portfolio::getNumberOfStocks() const
	{

		return ownedStocks.size();
	}

	//Function to return the number of bonds in the bond vector
	int portfolio::getNumberOfBonds() const
	{
		return ownedBonds.size();
	}

	//Function to return a stock at a given index in the stock vector
	stock portfolio::getStock(int index) const
	{
		return ownedStocks.at(index);
	}

	//Function to tokenize the date
	void portfolio::tokenizeDate(char* cDate, int& month, int& day, int& year)
	{
		//Delimiter set to the '/'
		char seps[] = "/";

		//pointer for current character set to NULL
		char* token = NULL;

		//Pointer for next character set to NULL
		char* next_token = NULL;

		token = NULL;
		next_token = NULL;

		//Establish string and get the tokens:  
		token = strtok_r(cDate, seps, &next_token);
		month = atoi(token);
		token = strtok_r(NULL, seps, &next_token);
		day = atoi(token);
		token = strtok_r(NULL, seps, &next_token);
		year = atoi(token);
	}

	//Function to return the name value for the portfolio
	string portfolio::getName() const
	{
		return name;
	}

	//Function to set the portfolio name
	void portfolio::setName(string inputName)
	{
		name = inputName;
	}

	//Function to sort the stock vector based on ticker symbol
	void portfolio::sortStockVector(vector<stock> &stockVector)
	{
		//For each character in the list finds the correct place
		for (int startingPoint = 0; startingPoint < stockVector.size() - 1; startingPoint++)
		{
			//Temp stock variable as a placeholder when swapping positions
			stock placeHolder;
			
			//Checks all other characters to find where this one should go
			for (int i = startingPoint + 1; i < stockVector.size(); i++)
			{
				//If a future stock is less than the current stock switch places
				if (stockVector[i] < stockVector[startingPoint])
				{
					//Swaps places using a placeholder variable as an intermitten step
					placeHolder = stockVector[startingPoint];
					stockVector[startingPoint] = stockVector[i];
					stockVector[i] = placeHolder;
				}

			}
		}
	}

	//Function to sort the bond vector based on the issuer
	void portfolio::sortBondVector(vector<bond>& bondVector)
	{
		//Loops through each bond to find it's correct position
		for (int startingPoint = 0; startingPoint < bondVector.size() - 1; startingPoint++)
		{
			//placeholder variable for swapping
			bond placeHolder;

			//loops through all characters after this one and if one is less than it, swaps places
			for (int i = startingPoint; i < bondVector.size(); i++)
			{
				//If a future bond's issuer is less than this one's they swap places
				if (bondVector[i] < bondVector[startingPoint])
				{
					//Swaps places using placeholder as intermitten step
					placeHolder = bondVector[startingPoint];
					bondVector[startingPoint] = bondVector[i];
					bondVector[i] = placeHolder;
				}

			}
		}
	}


	//constructors

	//Default constructor initializes name to ""
	portfolio::portfolio()
	{
		name = "";


	}

	//constructor that initializes name to input name
	portfolio::portfolio(std::string inputName)
	{
		name = inputName;
	}



	//Destructor
	portfolio::~portfolio()
	{

	}