//Represents the Savings Data Collection of a backend banking system, the Savings account can have money deposited into it but not withdrawn
//The savings account also has a mutable interest rate
#pragma once

#include "Account.h"

class Savings : public Account
{
public:
	Savings(); 
	Savings(const std::string& first, const std::string& last, double& interest); 
	double getInterestRate() const; 
	void setInterestRate( double& interest ); 
	virtual void display() const override; 
protected:
	double interestRate{ 0.0 }; 
};
