/*
* Name   : practical1_test.cpp
* Purpose: To test the Account class
* Author : Your name here
* Version: 1.0
*/

// Use this definition when providing your own main method
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "Account.h"

using namespace std;

/**
* Account Test Axioms
*/
TEST_CASE("Account Axioms", "[Account]")
{
	// arrange new customer with a zero balance and zero overdraft
	Account a("Bloggs");

	SECTION("Construct an Account")
	{
		//assert customer is Bloggs
		REQUIRE(a.getCustomer() == "Bloggs");
		// assert balance is 0.0
		REQUIRE(a.getBalance() == 0.0);
		//assert overdraft is 0.0
		REQUIRE(a.getOverdraft() == 0.0);
	}

	SECTION("Deposit Legal Amount")
	{
		// act
		a.deposit(50);

		// assert balance is 50
		REQUIRE(a.getBalance() == 50.0);
	}

	SECTION("Attempt to Deposit Illegal Amount")
	{
		// act
		a.deposit(-50);

		// assert balance unchanged
		REQUIRE(a.getBalance() == 0.0);
	}

	SECTION("Withdraw Legal Amount")
	{
		// act
		a.deposit(100.0);
		a.withdraw(10.0);

		// assert balance is 90
		REQUIRE(a.getBalance() == 90.0);
	}

	SECTION("Attempt to Withdraw Illegal Amount")
	{
		// act
		a.deposit(100.0);
		a.withdraw(110.0);

		// assert balance still 100
		REQUIRE(a.getBalance() == 100.0);
	}

	SECTION("Withdraw Using Overdraft")
	{
		// act
		a.deposit(100.0);
		a.setOverdraft(50);
		a.withdraw(110.0);

		// assert balance overdrawn by -10
		REQUIRE(a.getBalance() == -10.0);
	}

	SECTION("Set Legal overdraft")
	{
		// act
		a.setOverdraft(50.0);

		// assert balance unchanged
		REQUIRE(a.getOverdraft() == 50.0);
	}

	SECTION("Attempt to set Illegal overdraft")
	{
		// act
		a.setOverdraft(-50.0);

		// assert balance unchanged
		REQUIRE(a.getOverdraft() == 0.0);
	}

	SECTION("Attempt to Set overdraft that does not cover overdrawn balance")
	{
		// act
		a.setOverdraft(10.0);
		a.withdraw(10.0);
		// change would not cover overdrawn amount
		a.setOverdraft(0.0);

		// assert overdraft unchanged
		REQUIRE(a.getOverdraft() == 10.0);
	}

}



 // ---------------------- ACCOUNT INTERACTIVE MENU ----------------------

// Post: Print menu, accept user character input and return uppercase character
char getOption() {
	char option;
	cout << endl << "P-print, D-deposit, W-withdraw, O-overdraft, Q-quit: ";
	cin >> option;
	// toupper is a standard C++ method which converts a char to uppercase (if possible)
	return toupper(option);
}

// menu method displays menu and repeatedly processes user inputs until Quit option selected
void menu() {

	float amount;				// user input
	char option = getOption();	// get initial user option

	Account a("Joe Bloggs");

	// sentinel controlled loop repeats until option is 'Q' (quit)
	while (option != 'Q') {
		if (option == 'D') {	// deposit option
			cout << "Enter amount to deposit: ";
			cin >> amount;
			a.deposit(amount);
		}
		else if (option == 'W') {	// withdraw option
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			// check that account has sufficient funds
			if (amount <= a.getBalance() + a.getOverdraft()) {
				a.withdraw(amount);
			}
			else {
				cout << "Insufficient funds" << endl;
			}
		}
		else if (option == 'P') {
			// print account details
			cout << a.toString() << endl;
		}
		else if (option == 'O') {	// overdraft option
			cout << "Enter new overdraft: ";
			cin >> amount;
			a.setOverdraft(amount);
		}

		// get next option 
		option = getOption();
	}

	cout << "Thankyou for using Account program" << endl;
}


// ----------- Main method calls catch and menu ------------

int main(int argc, char* argv[]) {

	// run the tests
	int result = Catch::Session().run(argc, argv);

	// run the account menu system
	menu();

	// ---------------------------------------------------
	std::cout << std::endl << "Press enter to quit";
	std::cin.get();

	return result;
}