//Portfolio -- This program creates a portfolio to track and organize the creation of stocks and bonds.
//CSIS 112-B01 

//<Sources if necessary>

//Include statements 
#include <iostream> 
#include <string> 
#include <iomanip>
#include "portfolio.h"
using namespace std;


//Function prototypes
void displayMenu();
char getInputInstruction();
void runInstruction(char instructionToExecute, portfolio& thisPortfolio);

int main()
{
	//Print statement for name and assignment number
	cout << "Hayden Eubanks -- Programming Assignment 7" << endl << endl;




	//Variable declarations 
	//
	//Variable to store the input instruction for the menu instructions
	char inputInstruction = 'Q';

	//Variable for the temporary input of the name to be passed to the portfolio on creation
	string tempInputName;

	//Variable to store the number of bonds
	int numberOfBonds = 0;




	//Program logic

	//Prompts the user for the name of the portfolio
	cout << "Please enter a name for your portfolio.\n\n";
	cout << "Portfolio Name: ";
	getline(cin, tempInputName);
	cout << endl << endl;

	//Creates a new portfolio with that name
	portfolio currentPortfolio(tempInputName);


	//Sets the decimal format to floating point and to two deciaml places since the output is in dollars
	cout << fixed << setprecision(2);

	//Calls Function to display the menu
	displayMenu();

	//Gets the input for the entered instruction and stores it in inputInstruction
	inputInstruction = getInputInstruction();

	//Calls function to run the correct instruction based on the input instruction
	runInstruction(inputInstruction, currentPortfolio);

	//Continue looping over this while the entered instruction is not Q to quit the program
	while (inputInstruction != 'Q')
	{
		//Calls FUnction to display the menu
		displayMenu();

		//Gets the input for the entered instruction and stores it in inputInstruction
		inputInstruction = getInputInstruction();

		//Calls function to run the entered instruction
		runInstruction(inputInstruction, currentPortfolio);
	}

	//Closing program statements 
	cout << "Exiting Program.\n\n";
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
	return 0;
}





//Function definitions


//Function to display the main menu
void displayMenu()
{
	cout << "\tMain Menu\n";
	cout << "S: Purchase Stock\n";
	cout << "B: Purchase Bond\n";
	cout << "L: List Portfolio Items\n";
	cout << "Q: Quit Program\n\n";
}



//Function to get the input Instruction from the user
char getInputInstruction()
{
	//Char variable to store the instruction
	char enteredInstruction;

	//Prompts user for the instruction
	cout << "Instruction: ";
	cin >> enteredInstruction;

	//Sets instruction to uppercase
	enteredInstruction = toupper(enteredInstruction);


	//Error checking: Must be one of the possible menu options
	if (cin.fail() || (enteredInstruction != 'S' && enteredInstruction != 'B' && 
		enteredInstruction != 'L' && enteredInstruction != 'Q'))
	{
		cout << "Entry Invalid. Entered Instruction must be S, B, L, or Q.\n";
		cout << "please try again.\n\n";
		cout << "Instruction: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> enteredInstruction;
		enteredInstruction = toupper(enteredInstruction);
		cout << endl << endl;
	}

	//Returns the entered instruction
	return enteredInstruction;


}



//Function to run the instruction entered by the user
void runInstruction(char instructionToExecute, portfolio& thisPortfolio)
{
	//If the instruction = s than run the purchase stock instruction
	if (instructionToExecute == 'S')
	{
		thisPortfolio.purchaseStocks();
	}

	//If the instruction is B run the purchase bond instruction
	else if (instructionToExecute == 'B')
	{
		thisPortfolio.purchaseBonds();
	}

	//If the instruction is L run the list instruction 
	else if (instructionToExecute == 'L')
	{
		cout << endl << endl;
		thisPortfolio.listPortfolio();
	}


	cout << endl << endl;

}