// Lab 1: Amortization
// Name: Sam McDowell
// Date: 09/01/2023

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void wait();
void getInputs(double& principal, int& life, double& interestRate);
double getMonthlyInterestRate(double interestRate);
int getLifeInMonths(int life);
double getMonthlyPayment(double principal, int life, double interestRate);
void printLoanInformationTable(double principal, int life, double interestRate, double monthlyPayment);
void amortize(int paymentPeriod, double remainingPrincipal, double monthlyInterestRate, int lifeInMonths, double monthlyPayment);

int main()
{
    // Initialize Variables
    double principal{ 0.0 };
    int life{ 0 };
    int lifeInMonths{ 0 };
    double interestRate{ 0.0 };
    double monthlyInterestRate{ 0.0 };
    double monthlyPayment{ 0 };
    int paymentPeriod{ 1 };

    // Print a title
    cout << "Loan Application - Amortization Scheduler\n" << endl;

    // Ask the user for the inputs (principal, life and rate)
    getInputs(principal, life, interestRate);

    // Find the monthly interest rate
    monthlyInterestRate = getMonthlyInterestRate(interestRate);

    // Find the total number of months
    lifeInMonths = getLifeInMonths(life);

    // Get the monthly payment
    monthlyPayment = getMonthlyPayment(principal, lifeInMonths, monthlyInterestRate);

    // Print a loan summary table for the user
    printLoanInformationTable(principal, life, interestRate, monthlyPayment);

    // Generate the amortization table using recursion
    amortize(paymentPeriod, principal, monthlyInterestRate, lifeInMonths, monthlyPayment);

    // Pause to wait for the user to continue
    wait();

    return 0;
}

/*
* Get the loan information from the user.
* If an item is entered in an invalid format, the user will be re-prompted for the information
* Parameters:
* principal - The full value of the loan in dollars
* life - The full lifetime of the loan in years
* interestRate - The annual interest rate entered as a percentage and saved as a decimal
*/
void getInputs(double& principal, int& life, double& interestRate) {

    /* Get the loan principal */
    cout << "Enter the loan principal: " << endl;
    cin >> principal;
    
    // Check that the input is correct (Derived from code written by Dr. Poole)
    while (cin.fail() || principal < 0) {
        cout << "You must enter a positive dollar amount. Please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> principal;
    }

    /* Get the life of the loan */
    cout << "Enter the life of the loan (5, 10, or 15): " << endl;
    cin >> life;

    // Check that the input is correct (Derived from code written by Dr. Poole)
    while (cin.fail() || (life != 5 && life != 10 && life != 15)) {
        cout << "The lifetime of the loan must be 5, 10, or 15 years. Please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> life;
    }

    /* Get the interest rate */
    cout << "Enter the annual interest rate percentage: " << endl;
    cin >> interestRate;

    // Check that the input is correct (Derived from code written by Dr. Poole)
    while (cin.fail() || interestRate < 0) {
        cout << "You must enter a positive interest rate. Please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> interestRate;
    }

    // Store the rate as a decimal
    interestRate = interestRate / 100;
}

/*
* Given the annual interest rate, return the monthly interest rate
* Parameters:
* interestRate - the annual interest rate of the loan
* Return:
* The monthly interest rate of the loan
*/
double getMonthlyInterestRate(double interestRate) {
    // Divide the annual interest rate by 12 to get the monthly interest rate
    return interestRate / 12;
}

/*
* Convert the life of the loan to months given the number of years
* Parameters:
* life - the lifetime of the loan in years
* Return:
* The number of months in the lifetime of the loan
*/
int getLifeInMonths(int life) {
    // The number of total months is the length of the loan times twelve months per year
    return life * 12;
}

/*
* Calculate the monthly payment of the loan applicant
* Parameters:
* principal - the total value of the loan in dollars
* lifeInMonths - the lifetime of the loan in months
* monthlyInterestRate - the rate of interest per month as a percentage
* Return:
* The monthly payment to pay off the loan by the end of the lifetime
* (Algorithm courtesy Dr. Poole)
*/
double getMonthlyPayment(double principal, int lifeInMonths, double monthlyInterestRate) {
    return principal * ((monthlyInterestRate * 
        pow(1+monthlyInterestRate, lifeInMonths)) / 
        (pow(1+monthlyInterestRate, lifeInMonths) - 1));
}

/*
* Print a table of the loan information
* Parameters:
* principal - the total value of the loan in dollars
* life - the lifetime of the loan in years
* interestRate - the annual interest rate
* monthlyPayment - the payment per month
*/
void printLoanInformationTable(double principal, int life, double interestRate, double monthlyPayment) {
    cout << "\n\n";
    cout << "Loan Application Summary\n" << endl;
    cout << left << setw(40) << "Principal" << right << setprecision(0) << fixed << principal << endl;
    cout << left << setw(40) << "Life of Loan" << right << life << endl;
    cout << left << setw(40) << "Interest Rate" << right << setprecision(2) << fixed << interestRate * 100 << "%" << endl;
    cout << left << setw(40) << "Monthly Payment" << right << setprecision(2) << fixed << monthlyPayment << endl;
    cout << endl;
}

/*
* Calculate the amortization of the loan and print a new line in the table for this period.
* This function should be called with the initial values and will complete recursively.
* Parameters:
* paymentPeriod - The payment number (the number of monthly payments made)
* remainingPrincipal - The value of the loan still to be paid off
* monthlyInterestRate - The monthly interest rate of the loan as a decimal
* lifeInMonths - The total lifetime of the loan in months
* monthlyPayment - The dollar amount paid towards the loan every period (or every month)
*/
void amortize(int paymentPeriod, double remainingPrincipal, double monthlyInterestRate, int lifeInMonths, double monthlyPayment) {
    // Check if this is the first run
    if (paymentPeriod == 1) {
        // Print the header for the table
        cout << right << setw(10) << "Payment";
        cout << right << setprecision(2) << fixed << setw(10) << "Amount";
        cout << right << setprecision(2) << fixed << setw(10) << "Interest";
        cout << right << setprecision(2) << fixed << setw(10) << "Principal";
        cout << right << setprecision(2) << fixed << setw(15) << "Balance";
        cout << endl;
        cout << right << setprecision(0) << fixed << setw(55) << remainingPrincipal << endl;
    }

    // Calculate the value for each column
    double thisPeriodInterest = remainingPrincipal * monthlyInterestRate;
    double thisPrincipalPayment = monthlyPayment - thisPeriodInterest;
    double nextPrincipal = remainingPrincipal - thisPrincipalPayment;

    // Print the values for each column to the screen
    cout << right << setw(10) << paymentPeriod;
    cout << right << setprecision(2) << fixed << setw(10) << monthlyPayment;
    cout << right << setprecision(2) << fixed << setw(10) << thisPeriodInterest;
    cout << right << setprecision(2) << fixed << setw(10) << thisPrincipalPayment;
    cout << right << setprecision(2) << fixed << setw(15) << abs(nextPrincipal);
    cout << endl;

    // Check the base case and decide whether to exit or continue recursing
    if (paymentPeriod == lifeInMonths) {
        // No more amortization to do, exit
        return;
    }
    else {
        // Continue amortizing
        amortize(paymentPeriod + 1, nextPrincipal, monthlyInterestRate, lifeInMonths, monthlyPayment);
    }

}

/*
* This method replicates the functionality of the windows pause feature
* by waiting for a character using cin.
* 
* Courtesy of Dr. Sipantzi
*/
void wait()
{
    //The following if-statement checks to see how many characters are in cin's buffer
    //If the buffer has characters in it, the clear and ignore methods get rid of them.
    if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer
    }
    char ch;
    cout << "Press the Enter key to continue ... ";
    cin.get(ch);
}
