// Lab 3: Employee Management System
// Name: Sam McDowell
// Date: 09/27/2023

#include <iostream>
#include <string>
#include <fstream>
#include "Employee.h"

using namespace std;

/* Functions  */
void printMenu(Employee e);
int getSelection();
bool switchEmployee(Employee &e);
Employee createNewEmployee();
void addScoreToEmployee(Employee &e);
void saveCurrentEmployee(Employee e);
void wait();

int main() {
    // Initialize variables
    Employee employee;
    int selection{ 0 };
    bool shouldExit{ false };
    bool success = true;

    // Repeat for as long as the user is using the program
    while (!shouldExit) {
        // Print the menu and get a selection
        printMenu(employee);
        selection = getSelection();

        // Handle the selection
        switch (selection)
        {
        case 1: // Change the employee
            success = switchEmployee(employee);
            if (!success) {
                shouldExit = true;
            }
            break;
        case 2: // Create a new employee
            employee = createNewEmployee();
            break;
        case 3: // Add a score to the employee
            addScoreToEmployee(employee);
            break;
        case 4: // Save the employee to a file
            saveCurrentEmployee(employee);
            break;
        case 5: // Show information about the employee
            employee.printEmployeeInfo();
            break;
        case 6: // Exit the program
            shouldExit = true;
            break;
        }
        cout << "\n\n";
    }

    // Print an exit message
    cout << "Thank you for using WePaintHouses LLC Employee Management System" << endl;
    cout << "Exiting.\n" << endl;

    // Pause for the user before final exit
    wait();
}

/*
* Print the menu
* Parameters:
* e - The employee currently loaded
*/
void printMenu(Employee e) {
    // Print the menu
    cout << "*****************************************************" << endl;
    cout << "                      MENU                           " << endl;
    cout << "Current Employee:\t" << e.getName() << endl;
    cout << endl;
    cout << "1 -\tSwitch/Open Employee File" << endl;
    cout << "2 -\tCreate New Employee" << endl;
    cout << "3 -\tAdd Score to Current Employee" << endl;
    cout << "4 -\tSave Current Employee Info to File" << endl;
    cout << "5 -\tPrint Employee Info" << endl;
    cout << "6 -\tQuit" << endl;
    cout << endl;
    cout << "*****************************************************\n" << endl;
}

/*
* Get the user's choice of the menu items.
* This will prompt the user and wait for an input from 1-6
* Return:
* The user selection as an int
*/
int getSelection() {
    int temp{ 0 };

    // Prompt the user
    cout << "Please select your menu choice: ";
    cin >> temp;

    // Check that the input is correct (Derived from code written by Dr. Poole.)
    while (cin.fail() || temp < 1 || temp > 6) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "That number is not an option." << endl;
        cout << "Please select your menu choice: ";

        cin >> temp;
    }

    return temp;
}

/*
* Change the employee that is currently open.
* Parameters:
* e - An Employee object to replace with the new employee
* Return:
* Whether the employee was updated - True if it was, False if an error occurred.
*/
bool switchEmployee(Employee &e) {
    string filename;
    string line;
    string name;
    string city;
    string id;
    double num = 0;
    bool success = true;

    // Prompt the user for a filename
    cout << "Please enter the name of the employee file (including extension): ";
    cin.ignore();
    getline(cin, filename);

    // Open the file for reading
    ifstream file(filename);

    // Make sure the file exists
    if (!file) {
        // If it does not exist, exit without updating
        cout << "File does not exist.";
        success = false;
    }
    else {
        // If it does exist, continue reading the information

        // Get the name from the first line of the file.
        getline(file, name);
        if (name == "") {
            // If the name is not valid, exit without updating
            success = false;
            cout << "File does not include a name. Exiting." << endl;
        }
        else {
            // Otherwise update the name
            e.setName(name);
        }
        
        // Get the city from the next line
        if (success) {
            getline(file, city);
            if (city == "") {
                // If the city is not valid exit without updating
                success = false;
                cout << "File does not include a city. Exiting." << endl;
            }
            else {
                // Otherwise update the city
                e.setCity(city);
            }
        }

        // Get the id from the next line
        if (success) {
            getline(file, id);
            if (id == "") {
                // If the id is not valid exit without updating
                success = false;
                cout << "File does not include an ID. Exiting." << endl;
            }
            else {
                // Otherwise update the id
                e.setID(id);
            }
        }

        // Get the scores from the file
        while (!file.fail() && num >= 0 && num <= 5 && success) {
            file >> num;

            // The input is not a double
            if (file.fail() && !file.eof()) {
                cout << "The file has non-numeric scores. Exiting.\n" << endl;
                success = false;
            }
            // The input is the end of the file
            else if (file.fail() && file.eof()) {
                cout << "Successfully read file." << endl;
            }
            // The input is a double
            else {
                // Attempt to add the score
                bool valid = e.addScore(num);
                // If the score is not valid, alert the user.
                if (!valid) {
                    cout << "Scores must be between 1 and 5. Exiting.\n" << endl;
                    success = false;
                }
            }
        }
    }

    // Close the file
    file.close();

    // If the update was not a success, clear any partially updated data
    if (!success) {
        e = Employee();
    }

    return success;
}

/*
* Create a new employee.
* This will set the name, city, id
* and a starting score.
* Return:
* The newly created employee
*/
Employee createNewEmployee() {
    string name;
    string city;
    string id;
    double score;
    bool success = true;
    Employee e;

    cin.ignore();
    // Get the name of the new employee
    cout << "Please enter the name of the employee: ";
    getline(cin, name);
    e.setName(name);

    // Get the city for the new employee
    cout << "Please enter the city where the employee will be working: ";
    getline(cin, city);
    e.setCity(city);

    // Get the id of the new employee
    cout << "Please enter the id of the employee: ";
    getline(cin, id);
    e.setID(id);

    cin.clear();

    // Get a satisfaction score for the new employee
    addScoreToEmployee(e);

    return e;
}

/*
* Add a score to the employee.
* Parameters:
* e - The employee to add the score for
*/
void addScoreToEmployee(Employee& e) {
    double score = 0.0;
    bool success = true;

    // Prompt the user for a score
    cout << "Please enter a satisfaction score: ";
    cin >> score;
    if (!cin.fail()) {
        success = e.addScore(score);
    }
    // Continue asking until a valid score is entered (Derived from code by Dr. Poole)
    while (cin.fail() || !success) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "That is not a valid score. Enter a number from 1 to 5." << endl;
        cout << "Please enter a satisfaction score: ";

        cin >> score;

        // If a number was entered, attempt to add it
        if (!cin.fail()) {
            success = e.addScore(score);
        }
    }
}

/*
* Save the current employee to a file
* Parameters:
* e - The employee to save
*/
void saveCurrentEmployee(Employee e) {
    string name;

    // Alert the user what the filename will be
    name = e.getName() + ".txt";
    cout << "Filename is set to " << name << endl;

    // Open the file
    ofstream file(name);

    // Write the name, city, id and scores in the format used to load an employee
    file << e.getName() << endl;
    file << e.getCity() << endl;
    file << e.getID() << endl;
    for (double i : e.getScores()) {
        file << i << endl;
    }

    // Close the file
    file.close();

    cout << "Saved all employee information. Returning to menu." << endl;
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