// Created by Alex Hoerr and Anastasiia Popovych
//Testing driver for banking backend account handling software, allows the creation of three tyes of accounts Savings, Checking,
//and Premium Checking all derived from a base account model. The testing driver allows the user to create accounts with,
//random data values and display all accounts that have been created

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <random>
#include "Account.h"
#include "Checking.h"
#include "PremiumChecking.h"
#include "Savings.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::default_random_engine;
using std::uniform_int_distribution;

//Methods
unsigned selectionMenu();
string randomName(default_random_engine&, const vector<string>&);
void genCheckingAccounts(int, vector<Account*>&, default_random_engine&, const vector<string>&, const vector<string>&);
void genPremiumCheckingAccounts(int, vector<Account*>&, default_random_engine&, const vector<string>&, const vector<string>&);
void displayAccounts(const vector<Account*>&);
void genSavingsAccounts(int, vector<Account*>&, default_random_engine&, const vector<string>&, const vector<string>&);  

int main()
{
	//Expandable lists of first and last names that the random name generator can pick from
	vector<string> fnames = 
	{
		"Matt", "Clark", "Cindy", "Joe", "Aasav", "Aaron", "Samantha", "Beth", "Bart"
	};

	vector<string> lnames =
	{
		"Smith", "Johnson", "Kent", "Liftman", "Crownings", "Backers", "Stone", "Powers"
	};

	//Stores all types of accounts that are created in the driver
	vector<Account*> accRegistry{};

	//Instanciate random integer engine
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };


	//Main loop, program runs until user terminates or selects the quit option
	unsigned selectionOperator{ 0 };
	while (selectionOperator != 5) 
	{
		//Displays a selection menu that allows the user to decide if they want to add accounts, display accounts, or exit
		selectionOperator = selectionMenu();


		int numAcc;
		switch (selectionOperator) {
		//Generates a specified number of checking accounts and displays the accounts details
		case 1:
			cout << "How many checking accounts would you like to create? ";
			cin >> numAcc;
			genCheckingAccounts(numAcc, accRegistry, engine, fnames, lnames);
			break;
			//Generates a specified number of checking accounts and displays the accounts details
		case 2:
			cout << "How many premium checking accounts would you like to create? ";
			cin >> numAcc;
			genPremiumCheckingAccounts(numAcc, accRegistry, engine, fnames, lnames);
			break;
		//Generate a specified number of saving accounts and displays the accounts details
		case 3:
			cout << "How many savings accounts would you like to create? ";
			cin >> numAcc ;
			genSavingsAccounts(numAcc, accRegistry, engine, fnames, lnames) ; 
			break;
		//Displays all of the accounts in the vector
		case 4:
			displayAccounts(accRegistry);
			break;
		//Exits Program
		case 5:
			cout << "Exiting Program..." << endl;
			break;
		default:
			cout << "Please select a valid option(1-5)." << endl << endl;
		}



	}
}

//Displays a slection menu that allows the user to pick which operation they would like to do
//Returns the users selection, an unsigned integer
unsigned selectionMenu()
{
	cout << "MENU: \n"
		<< "1. Create Checking accounts\n"
		<< "2. Create Premium accounts\n"
		<< "3. Create Savings accounts\n"
		<< "4. Display all accounts\n"
		<< "5. Quit\n"
		<< "Selection : ";

	unsigned selectionOperator;
	cin >> selectionOperator;
	cout << "" << endl;

	return selectionOperator;
}

//Generates a random name using one of the random name vectors
//Passes in a random number generation engine by reference to handle the random generation of names
string randomName(default_random_engine& engine, const vector<string>& names)
{
	uniform_int_distribution<unsigned int> randomInt{ 0, names.size() - 1};
	unsigned selection = randomInt(engine);
	return names[selection];
}

//Generates random checking accounts that vary in their names and amount totals
//Each generated account is displayed to the user and added to the Account List
void genCheckingAccounts(int numAcc, vector<Account*>& accList, default_random_engine& engine, const vector<string>& fnames, const vector<string>& lnames)
{
	uniform_int_distribution<unsigned long long> randomULL(1000, 92233720);
	for (int index = 0; index < numAcc; index++)
	{
		Account* tempAcc = new Checking(randomName(engine, fnames), randomName(engine, lnames));
		tempAcc->deposit(randomULL(engine));
		tempAcc->display();
		accList.push_back(tempAcc);
	}
}

//Generates random premium checking accounts that vary in their names and amount totals
//Each generated account is displayed to the user and added to the Account List
void genPremiumCheckingAccounts(int numAcc, vector<Account*>& accList, default_random_engine& engine, const vector<string>& fnames, const vector<string>& lnames)
{
	uniform_int_distribution<unsigned long long> randomULL(1000, 92233720);
	for (int index = 0; index < numAcc; index++)
	{
		Account* tempAcc = new PremiumChecking(randomName(engine, fnames), randomName(engine, lnames));
		tempAcc->deposit(randomULL(engine));
		tempAcc->display();
		accList.push_back(tempAcc);
	}
}

//Generate random savings accounts that varies in the account name and amount totals
//Also sets a random interest rate between 0 and 75%
void genSavingsAccounts( int numAcc, vector<Account*>& accList, default_random_engine& engine,
			const vector<string>& fnames, const vector<string>& lnames)
{
	uniform_int_distribution<unsigned long long> randomULL(1000, 92233720);
	//Sets the interest rate between 0.00005 and 75.00005% for testing reasons
	std::uniform_real_distribution<double> interestRate(.00005, 75.00005);
	for ( int index = 0 ; index < numAcc ; index++)
	{
		double interest = interestRate(engine);
		Account* tempAcc = new Savings(randomName(engine, fnames), randomName(engine, lnames), interest);
		tempAcc->deposit(randomULL(engine));
		tempAcc->display(); 
		accList.push_back(tempAcc); 
	}
}

//Displays the info of all accounts that have been generated by the user
void displayAccounts(const vector<Account*>& accList)
{
	for (unsigned index = 0; index < accList.size(); index++)
	{
		accList.at(index)->display();
	}
}
