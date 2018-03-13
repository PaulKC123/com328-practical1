/* *******************************************************
* Name   : Account.cpp
* Purpose: Implementation of an Account containing a balance
* Author : Your name here
* Version: 1.1
* ******************************************************/
#include "Account.h"
#include <string>

// PreCondition: the account has sufficient funds
// PostConditon: balance is reduced by amount
void Account::withdraw(float amount) {
	if (amount <= balance + overdraft) {
		balance -= amount;
	}
}

// PreCondition: amount is a positive non zero value
// PostCondition: amount is added to balance
void Account::deposit(float amount) {
	if (amount > 0) {
		balance += amount;
	}
}

// PostCondition: balance amount is returned
float Account::getBalance() const {
	return balance;
};

// PostCondition: overdraft amount is returned
float Account::getOverdraft() const {
	return overdraft;
};


// PreCondition: over is a positive amount
// PostCondition: overdtaft amount is changed
void Account::setOverdraft(float over) {
	if (over >= 0 && balance + over >= 0) {
		overdraft = over;
	}
};

// PostCondition: customer name is returned
std::string Account::getCustomer() const {
	return customer;
};

// PostCondition: customer name is updated
void Account::setCustomer(std::string cust) {
	customer = cust;
};

// PostCondition: returns true if customer is equal to other
//                account customer, false otherwise
bool Account::operator==(const Account & other) const {
	return (customer == other.customer) ;
}

// PostCondition: returns true if customer is less than other
//                account customer, false otherwise
bool Account::operator<(const Account & other) const {
	return (customer < other.customer);
}

// PostCondition: returns true if customer is greater than other
//                account customer, false otherwise
bool Account::operator>(const Account & other) const {
	return (customer > other.customer);
}

// PostCondition: returns string representation of account
std::string Account::toString() const {
	return  "Customer: " + customer + " Balance: " + std::to_string(balance) + " Overdraft: " + std::to_string(overdraft);
}

// PostCondition: prints account info to supplied ostream
void Account::print(std::ostream & out) const {
	out << toString();
}


// External overloaded << operator (not a class member function)
// PreCondition: None
// PostCondition: overload << operator to output Account on ostream
template <class T>
std::ostream& operator <<(std::ostream& output, const Account & a) {
	output << a.toString();
	// or alternatively
	//a.print(output);
	return output;  // for multiple << operators.
}
