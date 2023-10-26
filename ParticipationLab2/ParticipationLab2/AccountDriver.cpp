// Test program for Account hierarchy.
#include <iostream>
#include <iomanip>
#include "Account.h" // Account class definition
#include "CheckingAccount.h" // CheckingAccount class definition
using namespace std;

int main() {
	Account accountBase{ 50.0 }; // create Account object
	CheckingAccount accountChecking{ 80.0, 1.0 }; // create CheckingAccount object

	cout << endl << endl << endl;
	cout << fixed << setprecision(2);

	// display initial balance of each object
	cout << "accountBase balance: $" << accountBase.getBalance() << endl;
	cout << "accountChecking balance: $" << accountChecking.getBalance() << endl;

	cout << "\nAttempting to debit $25.00 from accountBase." << endl;
	accountBase.debit(25.0); // try to debit $25.00 from account1
	cout << "\nAttempting to debit $40.00 from accountChecking." << endl;
	accountChecking.debit(40.0); // try to debit $40.00 from account3

	// display balances
	cout << "\naccountBase balance: $" << accountBase.getBalance() << endl;
	cout << "accountChecking balance: $" << accountChecking.getBalance() << endl;

	cout << "\nCrediting $40.00 to accountBase." << endl;
	accountBase.credit(40.0); // credit $40.00 to account1
	cout << "\nCrediting $20.00 to accountChecking." << endl;
	accountChecking.credit(20.0); // credit $20.00 to account3

	// display balances
	cout << "\naccountBase balance: $" << accountBase.getBalance() << endl;
	cout << "accountChecking balance: $" << accountChecking.getBalance() << endl << endl;

	//Now it's your turn....
	/*Write a C++ program that will create an inheritance hierarchy that a bank might use to represent customers’ bank accounts.
	All customers at this bank can deposit(i.e.credit) money into their accounts and withdraw(i.e.debit) money from their accounts.
	More specific types of accounts also exist. Savings accounts, for instance, earn interest on the money they hold.
	Checking accounts, on the other hand, charge a fee per transaction(i.e.credit or debit).

	The goal of this exercise is to create an inheritance hierarchy containing base - class Account and a derived class,
	SavingsAccount, that inherits from class Account.

	Base - class Account has already been created for you and is included in this solution.
	It includes one data member of type double to represent the account balance.
	The class provides a constructor that receives an initial balance and uses it to initialize the data member.
	The constructor validates the initial balance to ensure that it’s greater than or equal to 0.0.
	If not, the balance is set to 0.0, and the constructor displays an error message, indicating that the initial balance was invalid.

	The Account class provides three member functions.
	Member function "credit" adds an amount to the current balance.
	Member function "debit" withdraws money from the account and ensures that the debit amount does not exceed the account’s balance.
	If it does, the balance is left unchanged and the function prints the message “Debit amount exceeded account balance.”
	Member function getBalance returns the current balance.

	It is your job to create the derived classes : SavingsAccount

	Derived-class SavingsAccount should inherit the functionality of Account, but also include a data member of
	type double indicating the interest rate (percentage) assigned to the account.
	SavingsAccount’s constructor should receive the initial balance, as well as an initial value
	for the SavingsAccount’s interest rate.
	SavingsAccount should provide a public member function calculateInterest that returns a double
	indicating the amount of interest earned by an account.
	Member function calculateInterest should determine this amount by multiplying the interest rate by the account balance.
	[Note: SavingsAccount should inherit member functions credit and debit as-is without redefining them.]

	After defining the classes in this hierarchy, it is time to test your code using the code below that creates objects
	of each class and tests their member functions.
	*/


	//Once your class is written, uncomment the lines below
	/**************************************************************************************************************/
	/*
	Account account1{ 50.0 }; // create Account object
	SavingsAccount account2{ 25.0, .03 }; // create SavingsAccount object
	cout << fixed << setprecision(2);

	// display initial balance of each object
	cout << "account1 balance: $" << account1.getBalance() << endl;
	cout << "account2 balance: $" << account2.getBalance() << endl;

	cout << "\nAttempting to debit $25.00 from account1." << endl;
	account1.debit(25.0); // try to debit $25.00 from account1
	cout << "\nAttempting to debit $30.00 from account2." << endl;
	account2.debit(30.0); // try to debit $30.00 from account2

	// display balances
	cout << "\naccount1 balance: $" << account1.getBalance() << endl;
	cout << "account2 balance: $" << account2.getBalance() << endl;

	cout << "\nCrediting $40.00 to account1." << endl;
	account1.credit(40.0); // credit $40.00 to account1
	cout << "\nCrediting $65.00 to account2." << endl;
	account2.credit(65.0); // credit $65.00 to account2

	// display balances
	cout << "\naccount1 balance: $" << account1.getBalance() << endl;
	cout << "account2 balance: $" << account2.getBalance() << endl;

	// add interest to SavingsAccount object account2
	double interestEarned = account2.calculateInterest();
	cout << "\nAdding $" << interestEarned << " interest to account2."
	<< endl;
	account2.credit(interestEarned);

	cout << "\nNew account2 balance: $" << account2.getBalance() << endl;

	*/
	/**************************************************************************************************************/





	system("pause");
	return 0;
}

