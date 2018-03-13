/* *******************************************************
* Name   : Account.h
* Purpose: Definition of an Account containing a balance
* Author : Your name here
* Version: 1.1
* ******************************************************/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>

class Account
{
public:

	// Constructor 
	Account(std::string name = "", float bal = 0, float over = 0) : customer{ name }, balance{ bal }, overdraft{ over } {}

	void withdraw(float amount);
	void deposit(float amount);
	float getBalance() const;

	std::string getCustomer() const;
	void setCustomer(std::string cust);

	float getOverdraft() const;
	void setOverdraft(float over);

	std::string toString() const;
	void print(std::ostream & out) const;

	bool operator==(const Account & other) const;
	bool operator<(const Account & other) const;
	bool operator>(const Account & other) const;

private:
	std::string customer;
	float balance;
	float overdraft;
};

#endif
