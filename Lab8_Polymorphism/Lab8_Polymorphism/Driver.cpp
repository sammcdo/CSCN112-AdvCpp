// Lab 8: Polymorphism
// Sam McDowell
// 12/1/2023

#include <iostream>
#include <string>
#include <random>

#include "Insect.h"
#include "Ant.h"
#include "Grasshopper.h"
#include "Beetle.h"
#include "Termite.h"

using namespace std;

const double ANT_SIZE[2] = {0.01, 1};
const double GRASSHOPPER_SIZE[2] = {10.5, 50};
const double BEETLE_SIZE[2] = {40, 75.5};
const double TERMITE_SIZE[2] = {1.5, 5.5};

const int COLLECTION_SIZE = 5;

void printTitle();
void printMenu();
int getMenuSelection();
string getColor();
void wait();

int main() {
    // Set up variables
    Insect* collection[COLLECTION_SIZE] = {NULL};
    bool isFinished{ false };
    int selection;
    string color;
    double size;
    int position{ 0 };

    random_device rdevice{};
    default_random_engine num{ rdevice() };

    // Create random distributions for each insect
    uniform_real_distribution<double> ant_sizer{ ANT_SIZE[0], ANT_SIZE[1]};
    uniform_real_distribution<double> grasshopper_sizer{ GRASSHOPPER_SIZE[0], GRASSHOPPER_SIZE[1] };
    uniform_real_distribution<double> beetle_sizer{ BEETLE_SIZE[0], BEETLE_SIZE[1] };
    uniform_real_distribution<double> termite_sizer{ TERMITE_SIZE[0], TERMITE_SIZE[1] };

    // Print the title
    printTitle();

    do {
        // Print the menu
        printMenu();

        // Get the user's selection
        selection = getMenuSelection();

        // Get the new insect's color
        color = getColor();

        // Respond based on which item was selected
        switch (selection) {
        case 1:  // Ant
            size = ant_sizer(num);
            collection[position] = new Ant(color, size);
            break;
        case 2:  // Grasshopper
            size = grasshopper_sizer(num);
            collection[position] = new Grasshopper(color, size);
            break;
        case 3:  // Beetle
            size = beetle_sizer(num);
            collection[position] = new Beetle(color, size);
            break;
        case 4:  // Termite
            size = termite_sizer(num);
            collection[position] = new Termite(color, size);
            break;
        default:
            break;
        }

        // Move our pointer in the array
        position++;

        // If we have moved to the end of the array, exit the loop
        if (position == COLLECTION_SIZE) {
            isFinished = true;
        }

    // Continue the previous steps until the array is full
    } while (!isFinished);

    cout << "\n\nDisplaying Insect Collection:\n\n";

    // Loop through the array and process them before deallocating them
    for (int i = 0; i < COLLECTION_SIZE; i++) {
        // Process each insect: call eat and print
        collection[i]->eat();
        cout << *collection[i] << endl;
        cout << endl;

        
    }

    // Make a second loop through the list and deallocate them
    for (int i = 0; i < COLLECTION_SIZE; i++) {
        // Deallocate the insect
        delete collection[i];
        collection[i] = NULL;
    }

    // Wait for user input to continue
    wait();

    return 0;
}

/*
* Print the title of the program
*/
void printTitle() {
    cout << "*************************************************" << endl;
    cout << "             Welcome to Insect Collector         " << endl;
    cout << "*************************************************" << endl;
}

/*
* Print the menu of the program
*/
void printMenu() {
    cout << "Collect an Insect:" << endl;
    cout << endl;
    cout << "1 - Ant" << endl;
    cout << "2 - Grasshopper" << endl;
    cout << "3 - Beetle" << endl;
    cout << "4 - Termite" << endl;
    cout << endl;
}

/*
* Get the users selection from the menu
* Return:
* An int representing their menu selection
*/
int getMenuSelection() {
    int selection;

    cout << "Selection: ";
    cin >> selection;

    // Make sure they enter a valid int
    while (cin.fail() || selection < 1 || selection > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Could not read selection. Please try again." << endl;
        cout << "Selection: ";

        cin >> selection;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return selection;
}

/*
* Prompt the user for the color of the insect
* Return:
* The color of the insect
*/
string getColor() {
    string color;
    cout << "Enter the color of the new insect: ";
    getline(cin, color);
    return color;
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