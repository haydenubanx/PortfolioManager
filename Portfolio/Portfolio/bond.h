#pragma once
#include <iostream> 
#include <string> 
#include "Date.h"
#include "security.h"



//Class for the bond derived from security. Declared as public so public members stay public 
//and private members stay private
class bond : public security
{
	//Overloading of the < operator compares two bonds by their issuer alphabetically
	friend bool operator< (const bond&, const bond&);



	
	//String to store the issuer
	std::string issuer;

	//Integer to store the face value
	int faceValue;

	//Double to store the decimal interest rate
	double statedInterestRate;

	//Date to store the maturity date
	Date maturityDate; 

	//Integer to store the number of bonds
	int numberOfBonds;



public:


	//Calculates the income (number of bonds * face value * interest rate)
	double calcIncome() const;

	//Returns the issuer value
	std::string getIssuer() const;

	//Sets the issuer value to the input value
	void setIssuer(std::string inputIssuer);

	//Returns the face value
	int getFaceValue() const;

	//Sets teh face vlue to the input value
	void setFaceValue(int inputFaceValue);

	//Returns the interest rate
	double getStatedInterestRate() const;

	//Sets the interest rate to the input value
	void setStatedInterestRate(double inputInterestRate);

	//Returns the maturity date
	Date getMaturityDate() const;

	//Sets the maturity date to the input value
	void setMaturityDate(Date inputMaturityDate);

	//returns the number of bonds
	int getNumberOfBonds() const;

	//sets the number of bonds to the input value
	void setNumberOfBonds(int numberInput);





	//default constructor sets issuer to "" and all other values to 0
	bond();
	

	//destructor
	~bond();
	
};