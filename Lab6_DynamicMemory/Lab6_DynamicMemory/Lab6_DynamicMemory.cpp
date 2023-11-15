// Lab6_DynamicMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#include "CompletedJob.h"

using namespace std;

int getNumberInvoices();
int getInvoiceMenu(int n);
CompletedJob* getJobFromInput();
CompletedJob* getJobFromFile();
string askForInvoiceFile();
void printInvoice(CompletedJob** jobs, ostream& out, int numInvoices);
void wait();

int main() {
    int numInvoices{ 0 };
    CompletedJob** jobs = NULL;
    int menuChoice{ 0 };
    string filename;

    // Seed random
    srand(1000);

    // Print a welcome header
    cout << "***************************************" << endl;
    cout << "           WePaintHouses LLC           " << endl;
    cout << "       Monthly Revenue Calculator      " << endl;
    cout << "***************************************" << endl;
    cout << endl;


    // Ask for number of invoices
    numInvoices = getNumberInvoices();

    // Dynamically create jobs array
    jobs = new CompletedJob* [numInvoices];

    // Read jobs from user
    for (int i = 0; i < numInvoices; i++) {
        menuChoice = getInvoiceMenu(i + 1);
        
        if (menuChoice == 1) {
            jobs[i] = getJobFromInput();
        }
        else {
            jobs[i] = getJobFromFile();
        }
    }

    // Write report
    filename = askForInvoiceFile();
    ofstream file(filename);
    printInvoice(jobs, cout, numInvoices);
    printInvoice(jobs, file, numInvoices);
    file.close();

    // Wait for the user before stopping the program
    wait();

    // Delete memory
    for (int i = 0; i < numInvoices; i++) {
        delete jobs[i];
        jobs[i] = NULL;
    }
    delete[] jobs;
    jobs = NULL;

    return 0;
}

/*
* Get the number of invoices being calculated
* Return:
* The number of invoices to process
*/
int getNumberInvoices() {
    int temp{ 0 };

    // Prompt the user
    cout << "Please enter the number of invoices to process: ";
    cin >> temp;

    // Check that the input is correct (Derived from code written by Dr. Poole.)
    while (cin.fail() || temp < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "You must enter a positive number of tasks." << endl;
        cout << "Please enter the number of invoices to process: ";

        cin >> temp;
    }

    // Clean cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return temp;
}

/*
* Print the menu for each invoice. 
* This offers to prompt the user for inputs or
* read from a file.
* It then error checks the response
* Return:
* The menu choice
*/
int getInvoiceMenu(int n) {
    int temp{ 0 };

    // Print the menu
    cout << "How would you like to load invoice " << n << "?" << endl;
    cout << "\t1: By user input" << endl;
    cout << "\t2: From a file" << endl;

    // Prompt the user
    cout << "Please enter your selection: ";
    cin >> temp;

    // Check that the input is correct (Derived from code written by Dr. Poole.)
    while (cin.fail() || temp < 1 || temp > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "You must enter a menu selection (1 or 2)" << endl;
        cout << "Please enter your selection: ";

        cin >> temp;
    }

    // Clean cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return temp;
}

/*
* Prompt the user for each component of a job.
* This includes asking for the name, rooms, labor charges,
* paint cans, product charges, mileage, and travel charges.
* This also error checks each input.
* Return:
* A pointer to a job filled with the data entered.
*/
CompletedJob* getJobFromInput() {
    CompletedJob* job = new CompletedJob();
    bool valid{ false };
    string clientName;
    int tempInt;
    double tempDouble;

    // Get the client name
    cout << "Please enter the client name: ";
    getline(cin, clientName);
    job->setClientName(clientName);
    
    // Ask for number of rooms painted
    while (!valid) {
        cout << "Please enter the number of rooms painted: ";
        cin >> tempInt;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            valid = false;
        }
        else {
            valid = job->setRoomsPainted(tempInt);
        }

        if (!valid) {
            cout << "Invalid number of rooms. Please enter a positive integer." << endl;
        }
    }

    // Ask for labor charges
    valid = false;
    while (!valid) {
        cout << "Please enter the labor charges: ";
        cin >> tempDouble;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            valid = false;
        }
        else {
            valid = job->setLaborCharges(tempDouble);
        }

        if (!valid) {
            cout << "Invalid labor charges. Please enter a positive number." << endl;
        }
    }

    // Ask for number of cans
    valid = false;
    while (!valid) {
        cout << "Please enter the number of cans used: ";
        cin >> tempInt;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            valid = false;
        }
        else {
            valid = job->setNumberOfPaintCans(tempInt);
        }

        if (!valid) {
            cout << "Invalid number of cans. Please enter a positive integer value." << endl;
        }
    }

    // Ask for product charges
    valid = false;
    while (!valid) {
        cout << "Please enter the product charges: ";
        cin >> tempDouble;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            valid = false;
        }
        else {
            valid = job->setProductCharges(tempDouble);
        }

        if (!valid) {
            cout << "Invalid product charges. Please enter a positive number." << endl;
        }
    }

    // Ask for mileage
    valid = false;
    while (!valid) {
        cout << "Please enter the job mileage: ";
        cin >> tempDouble;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            valid = false;
        }
        else {
            valid = job->setMileage(tempDouble);
        }

        if (!valid) {
            cout << "Invalid mileage. Please enter a positive number." << endl;
        }
    }

    // Ask for travel charges
    valid = false;
    while (!valid) {
        cout << "Please enter the travel charges: ";
        cin >> tempDouble;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            valid = false;
        }
        else {
            valid = job->setTravelCharges(tempDouble);
        }

        if (!valid) {
            cout << "Invalid travel charges. Please enter a positive number." << endl;
        }
    }

    // Clean cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return job;
}

/*
* Read the parameters of a job from a file
* This includes asking for the name, rooms, labor charges,
* paint cans, product charges, mileage, and travel charges.
* This also prompts for the filename
* Return:
* A pointer to a job filled with the data entered.
*/
CompletedJob* getJobFromFile() {
    CompletedJob* job = new CompletedJob();
    string filename;
    ifstream* file = NULL;
    bool fileWorks{ false };
    bool valid{ true };

    // Prompt until a valid file is found
    while (!fileWorks) {
        cout << "Enter the name of the file to read: ";
        getline(cin, filename);

        file = new ifstream(filename);

        if (file->good()) {
            fileWorks = true;
        }
        else {
            cout << "That file could not be accepted. Please try again." << endl;
        }
    }

    // Read the name
    string name;
    getline(*(file), name);
    job->setClientName(name);

    // Read the rooms
    int rooms;
    *(file) >> rooms;
    job->setRoomsPainted(rooms);

    // Read the labor charges
    double labor;
    *(file) >> labor;
    job->setLaborCharges(labor);

    // Read the number of cans
    int cans;
    *(file) >> cans;
    job->setNumberOfPaintCans(cans);

    // Read the product charges
    double product;
    *(file) >> product;
    job->setProductCharges(product);

    // Read the mileage
    double mileage;
    *(file) >> mileage;
    job->setMileage(mileage);

    // Read the travel charges
    double travel;
    *(file) >> travel;
    job->setTravelCharges(travel);
    
    // clean up
    file->close();
    delete file;
    file = NULL;

    return job;
}

/*
* Prompt the user for a filename to save
* the report
* Return:
* The filename selected
*/
string askForInvoiceFile() {
    string filename;

    cout << "Enter the filename to save the report:" << endl;

    getline(cin, filename);

    return filename;
}

/*
* Print the invoice.
* Write a header and information on each job to the given output
* Params:
* jobs - A pointer to an array of dynamically created CompletedJobs
* out - An ostream to write to
* numInvoices - The number of jobs contained in the jobs array
*/
void printInvoice(CompletedJob** jobs, ostream& out, int numInvoices) {
    double totalCost{ 0 };

    // Print the header
    out << "*************************************************" << endl;
    out << "               WePaintHouses LLC                 " << endl;
    out << "                  Revenue Report                 " << endl;
    out << "*************************************************" << endl;
    out << endl;
    out << "WePaintHouses LLC" << endl;
    out << "1971 University Blvd." << endl;
    out << "Lynchburg, VA 24515" << endl;
    out << "555-869-5309" << endl;
    out << "wepainthousesllc.com" << endl;
    out << endl;
    out << "-------------------------------------------------" << endl;
    
    // Loop through each job and print a summary
    for (int i = 0; i < numInvoices; i++) {
        double jobCost{ 0 };
        CompletedJob* job = jobs[i];
        out << "Client Name: " << job->getClientName() << endl;
        out << "\tRooms Painted: " << job->getRoomsPainted() << endl;
        out << "\tLabor Charges: " << fixed <<setprecision(2) << job->getLaborCharges() << endl;
        out << "\tPaint Cans: " << job->getNumberOfPaintCans() << endl;
        out << "\tProduct Charges: " << fixed << setprecision(2) << job->getProductCharges() << endl;
        out << "\tMileage: " << fixed << setprecision(2) << job->getMileage() << endl;
        out << "\tTravel Charges: " << fixed << setprecision(2) << job->getTravelCharges() << endl;

        jobCost = job->getLaborCharges() + job->getProductCharges() + job->getTravelCharges();

        out << "  Total Cost: " << right << setw(35) << setprecision(2) << fixed << jobCost << endl;
        out << endl;

        totalCost += jobCost;
    }

    // Print the final total
    out << "-------------------------------------------------" << endl;
    out << "Final Revenue:" << setw(35) << right << setprecision(2) << fixed << totalCost << endl;
    out << "-------------------------------------------------" << endl;
    
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