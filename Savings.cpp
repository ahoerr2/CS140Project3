#include "Savings.h" ; 

#include <iostream> 

//default constructor
Savings::Savings()
{}

//constructor
Savings::Savings(const std::string& first, const std::string& last, double& interest)
{
	firstName = first; 
	lastName = last; 
	interestRate = interest; 
}

//getter
double Savings::getInterestRate() const
{
	return interestRate; 
}

//setter 
void Savings::setInterestRate(double& interest)
{
	interestRate = interest; 
}

//display override 
void Savings::display()
{
	Account::display(); 
	std::cout << "Interest Rate: " << getInterestRate() << std::endl; 
}