#pragma once
#include <iostream> 
#include <string> 
#include "bond.h"
using namespace std;

//Overloads the < operator to compare bonds by issuer
bool operator< (const bond& inputBond, const bond& compareBond)
{
	//boolean expression to store if the right hand bond issuer is less than the lefthand bond issuer
	bool isLessThan = false;

	//Compares lefthand and righthand bond issuer
	if (inputBond.getIssuer() < compareBond.getIssuer())
	{
		//If lefthand is less than righthand, sets bool to true
		isLessThan = true;
	}

	//Returns the boolean expression
	return isLessThan;
}


	//Calculates teh bond income
	double bond::calcIncome() const
	{
		//calculates by multiplying the number of bonds by the face value by the interest rate
		double income = getQuantityPurchased() * getFaceValue() * getStatedInterestRate();

		//Returns the calculated value
		return income;
	}

	//Returns the bond issuer
	string bond::getIssuer() const
	{
		return issuer;
	}

	//Sets the bond issuer to the input value
	void bond::setIssuer(string inputIssuer)
	{
		issuer = inputIssuer;
	}

	//Returns the face value
	int bond::getFaceValue() const
	{
		return faceValue;
	}

	//Sets the face value to the input value
	void bond::setFaceValue(int inputFaceValue)
	{
		faceValue = inputFaceValue;
	}

	//Returns teh interest rate
	double bond::getStatedInterestRate() const
	{
		return statedInterestRate;
	}

	//Sets the interest rate to the input value
	void bond::setStatedInterestRate(double inputInterestRate)
	{
		statedInterestRate = inputInterestRate;
	}

	//Returns teh maturity date
	Date bond::getMaturityDate() const
	{
		return maturityDate;
	}

	//Sets the maturity date to teh input value
	void bond::setMaturityDate(Date inputMaturityDate)
	{
		maturityDate = inputMaturityDate;
	}

	//Returns the number of bonds
	int bond::getNumberOfBonds() const
	{
		return numberOfBonds;
	}

	//Sets the number of bonds to the input value
	void bond::setNumberOfBonds(int numberInput)
	{
		numberOfBonds = numberInput;
	}


	//constructor
	//default constructor sets issuer to "" and all other values to 0
	bond::bond()
	{
		setPurchasePrice(0);
		setQuantityPurchased(0);
		issuer = "";
		faceValue = 0;
		statedInterestRate = 0;
		numberOfBonds = 0;
	}

	//destructor
	bond::~bond()
	{

	}

