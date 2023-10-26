// Solution 11.10 Solution: Account.h
// Definition of Account class.
#pragma once

class Account {
public:
	Account(double); // constructor initializes balance
	void credit(double); // add an amount to the account balance
	bool debit(double); // subtract an amount from the account balance
	void setBalance(double); // sets the account balance
	double getBalance() const; // return the account balance
private:
	double balance; // data member that stores the balance
};




