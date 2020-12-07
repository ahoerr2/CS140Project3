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
