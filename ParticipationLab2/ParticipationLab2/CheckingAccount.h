// Definition of CheckingAccount class.
#pragma once

#include "Account.h" // Account class definition

class CheckingAccount : public Account {
public:
	// constructor initializes balance and transaction fee
	CheckingAccount(double, double);

	void credit(double); // redefined credit function
	bool debit(double); // redefined debit function
private:
	double transactionFee; // fee charged per transaction

	// utility function to charge fee
	void chargeFee();
};



