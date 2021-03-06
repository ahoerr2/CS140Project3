#include "Checking.h";
#include <iostream>

//Deafault Constructor
Checking::Checking()
{}
//Constructor sets the first and last names of the account
Checking::Checking(const std::string& first, const std::string& last)
{
	firstName = first;
	lastName = last;
}

//Withdraws a positive amount of money from the balance of the account
//Overdrawing on the account will cancel the transaction and penalitze the user with a fee
//The penaltiy is $10.00 for the first 3 overdraws and $30.00 for all other overdraws
void Checking::withdraw(unsigned long long amt)
{
	if (amt <= 0) 
	{
		std::cout << "Error, a withdrawl requires a postive integer amount be inputted." << std::endl;
		return;
	}

	if (amt > balance)
	{
		//Informs the user there was an overdraw and informs the user how much money is in the balance, adds an overdraw penalty to account
		std::cout << "Error, not enough money in balance( " << balance << " ) "
			<< "to process withdraw( " << amt << " ) " << std::endl;
		++overdrawnCount;
		
		//Informs the user and overdraw penalty has been administered and for how much
		std::cout << "A overdrawn penalty has been administered for ";
		if (overdrawnCount < 3) 
		{ 
			std::cout << "10.00$";
			balance -= 1000;
		}
		else 
		{
			std::cout << "30.00$"; 
			balance -= 3000;
		}
		std::cout << std::endl;
		return;
	}

	balance -= amt;

}

//Getter for the amount of overdraws to user has accrued
unsigned int Checking::getOverdrawnCount() const
{
	return overdrawnCount;
}

//Displays the info of the checking account
void Checking::display() const
{
	Account::display();
	std::cout << "Overdraw Total: " << getOverdrawnCount() << std::endl;
}