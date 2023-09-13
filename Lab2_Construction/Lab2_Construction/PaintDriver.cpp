// Lab 2: Painting Class
// Name: Sam McDowell
// Date: 09/15/2023

#include <iostream>
#include <iomanip>
#include "Room.h"

using namespace std;

// Global Variables
const int SQ_FEET_PER_GALLON_PAINT = 400;

// Functions
bool getInputs(double& length, double& width, double &height);
double getGallonsFromSqFeet(double squareFeet);
void wait();

int main()
{
    // Initialize Variables
    bool shouldExit{ false };
    bool isValid{ true };
    double length{ 0.0 };
    double width{ 0.0 };
    double height{ 0.0 };

    Room paintRoom;

    // Print a title
    cout << "Room Painting Cost Calculator" << endl;
    cout << "(Enter -1 to exit)\n" << endl;

    // The main program loop:
    // Allow the user to continue calculating until -1 is entered
    while (!shouldExit) {

        // Get the dimensions input from the user
        shouldExit = getInputs(length, width, height);

        // If getInputs alerts that a -1 was entered, do not continue
        if (!shouldExit) {

            // Set the length of the room
            isValid = paintRoom.setLength(length);

            // Set the width of the room (assuming the length was set successfully)
            if (isValid) {
                isValid = paintRoom.setWidth(width);
            }

            // Set the height of the room (assuming the previous dimensions were set successfully)
            if (isValid) {
                isValid = paintRoom.setHeight(height);
            }

            // If any of the previous dimensions were not set successfully, 
            // show an error message and re-prompt
            if (!isValid) {
                cout << "Invalid numbers entered. Please try again." << endl;
            }
            // All inputs are error free and user has not quit, continue execution
            else {

                // Print a table of the data
                cout << "\n";
                paintRoom.showData();

                // Print the number of gallons of paint needed
                cout << left << setw(20) << "Gallons of Paint:" << right << setprecision(2) << setw(10) << fixed
                    << getGallonsFromSqFeet(paintRoom.calcPaintedArea()) << endl;
                cout << "\n";
            }
        }
    }

    // Print an exit message
    cout << "\nThank you for using Room Paint Cost Calculator." << endl;
    cout << "Exiting.\n" << endl;

    // Pause to wait for the user to continue
    wait();
}

/*
* Get the room dimensions from the user.
* If any incorrect data is input the user will be re-prompted.
* If a -1 is entered, output an exit code.
* Parameters:
* length - The length of the room
* width - The width of the room
* height - The height of the room
* Return:
* Whether to exit - True if the exit code -1 has been entered, otherwise false
*/
bool getInputs(double& length, double& width, double& height) {
    // Initialize variables
    bool exit{ false };

    /* Get the room length */
    cout << "Enter the room length: ";
    cin >> length;

    // Check that the input is correct (Derived from code written by Dr. Poole)
    while (cin.fail()) {
        cout << "You must enter a numeric length. Please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> length;
    }

    // Check if we should exit
    if (length == -1) { 
        exit = true; 
    }

    /* Get the room width (only if -1 has not been entered already) */
    if (!exit) {
        cout << "Enter the room width: ";
        cin >> width;

        // Check that the input is correct (Derived from code written by Dr. Poole)
        while (cin.fail()) {
            cout << "You must enter a numeric width. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> width;
        }
    }

    // Check if we should exit
    if (width == -1) {
        exit = true;
    }

    /* Get the room length (only if -1 has not been entered already) */
    if (!exit) {
        cout << "Enter the room height: ";
        cin >> height;

        // Check that the input is correct (Derived from code written by Dr. Poole)
        while (cin.fail()) {
            cout << "You must enter a numeric height. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> height;
        }
    }

    // Check if we should exit
    if (height == -1) {
        exit = true;
    }

    return exit;
}

/*
* Convert a number of paintable square feet to gallons of paint.
* Parameters:
* squareFeet - The number of square feet being painted.
* Return:
* The number of gallons of paint required.
*/
double getGallonsFromSqFeet(double squareFeet) {
    return squareFeet / SQ_FEET_PER_GALLON_PAINT;
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