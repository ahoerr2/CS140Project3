#include "Savings.h" ; 

#include <iostream> 

//default constructor
Savings::Savings()
{}

//Loaded Constructor, takes in the name of the account holder and their set interest rate
Savings::Savings(const std::string& first, const std::string& last, double& interest)
{
	firstName = first; 
	lastName = last; 
	interestRate = interest; 
}

//Interest Rate Getter
double Savings::getInterestRate() const
{
	return interestRate; 
}

//Interest Rate Setter 
void Savings::setInterestRate(double& interest)
{
	interestRate = interest; 
}

//Displays the info of the savings account
void Savings::display() const
{
	Account::display(); 
	std::cout << "Interest Rate: " << getInterestRate() <<"%"<< std::endl; 
}
