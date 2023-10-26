// Lab 4: Painting Invoice System
// Name: Sam McDowell
// Date: 10/11/2023

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "House.h"
#include "Room.h"

using namespace std;

// Global Variables
const double PAINTER_HOURLY_RATE = 18.5;
const double MILEAGE_COST = 0.67;
const double PAINT_COST = 70.35;

// Functions
void getInputs(House& house);
void printMenu();
char getMenuSelection();
void addRoomToHouse(House& house);
void saveToFileOption(House& house);
inline double calcLabor(int coats);
inline double calcRoomTotal(double cans);
inline double calcTravelCost(double distance);
void printInvoice(ostream& stream, House house);
void wait();

int main()
{
    // Define variables
    House house;
    bool done{ false };
    char selection{ 'a' };
    bool saveToFile{ false };

    // Print a title
    cout << "WePaintHouses LLC Invoice Generator" << endl;

    // Get initial inputs
    getInputs(house);

    // Main menu loop
    while (!done) {
        // Prompt user and get their menu selection
        printMenu();
        selection = getMenuSelection();

        switch (selection) {
        // If they entered A, add a room
        case 'a':
        case 'A':
            addRoomToHouse(house);
            break;
        // If they entered L, list the rooms
        case 'l':
        case 'L':
            house.printRooms(cout);
            break;
        // If they enter Q, exit
        case 'q':
        case 'Q':
            done = true;
            break;
        default:
            cout << "That is not a valid menu selection.";
            break;
        }
        
        cout << "\n\n";
    }

    // Ask the user if they would like to save the invoice
    saveToFileOption(house);

    // Print the invoice for the user
    printInvoice(cout, house);

    // End so the user can read the invoice
    cout << "\n\n\n";
    wait();

    return 0;
}

/*
* Prompt the user for inputs, error check them and 
* update the given House with that new data.
* This will prompt for the client name, the maximum
* number of rooms and the distance to the client
* Parameters:
* house - The house object to modify
*/
void getInputs(House& house) {
    string name{ "" };
    int rooms{ 0 };
    double distance{ 0.0 };
    bool valid{ false };

    // Prompt the user for the client name
    cout << "Please enter the name of the client: ";
    getline(cin, name);
    cin.clear();

    // Store it in the house
    house.setOwnerName(name);

    // Prompt the user for the maximum number of rooms
    cout << "Please enter the maximum number of rooms that can be painted: ";
    cin >> rooms;

    // Continue asking until a valid number of rooms is entered.
    while (!valid) {
        // Check that the input is correct (Derived from code written by Dr. Poole.)
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "You must enter a numeric number of rooms:" << endl;
            cout << "Please enter the maximum number of rooms that can be painted: ";

            cin >> rooms;
        }

        // If the input is received as a valid int, attempt to save it
        valid = house.setMaxRooms(rooms);

        // If it cannot be saved to the house, reprompt
        if (!valid) {
            cout << "The number of rooms entered was invalid.";
            cout << "Please enter the maximum number of rooms that can be painted: ";

            cin >> rooms;
        }
    }

    // Prompt the user for the distance to the job
    cout << "Please enter the distance to the client (in miles): ";
    cin >> distance;
    valid = false; // Reset control variable

    // Continue asking until a valid distance is entered.
    while (!valid) {
        // Check that the input is correct (Derived from code written by Dr. Poole.)
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "You must enter a numeric distance:" << endl;
            cout << "Please enter the distance to the client (in miles): ";

            cin >> distance;
        }

        // If the input is received as a valid double, attempt to save it
        valid = house.setDistanceAway(rooms);

        // If it cannot be saved to the house, reprompt
        if (!valid) {
            cout << "The number of rooms entered was invalid.";
            cout << "Please enter the distance to the client (in miles): ";

            cin >> distance;
        }
    }
}

/*
* Print the user menu.
*/
void printMenu() {
    cout << "Please Select an Option:" << endl;
    cout << "[A] - Add a room to the house" << endl;
    cout << "[L] - List all the rooms currently in the house" << endl;
    cout << "[Q] - Quit and prepare the invoice" << endl;
}

/*
* Ask the user for a selection from the menu.
* Return:
* The char menu option the user typed.
*/
char getMenuSelection() {
    char temp{ 'x' };

    // Prompt the user
    cout << "Please select your menu choice: ";
    cin >> temp;

    // Check that the input is correct (Derived from code written by Dr. Poole.)
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "You must enter a single letter from the menu" << endl;
        cout << "Please select your menu choice: ";

        cin >> temp;
    }

    return temp;
}

/*
* Add a Room to the House.
* Prompts the user for length, width, 
* and height for a new Room and then 
* gives it to the House if there is 
* room
* Parameters:
* house - The House to add a Room to
*/
void addRoomToHouse(House& house) {
    double length{ 0 };
    double width{ 0 };
    double height{ 0 };
    int coats{ 0 };
    bool valid{ false };
    bool canAddRoom{ true };
    Room room;

    // Prompt the user for the length of the room
    cout << "Please enter the length of the room: ";
    cin >> length;

    // Continue asking until a valid length is entered.
    while (!valid) {
        // Check that the input is correct (Derived from code written by Dr. Poole.)
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "You must enter a numeric length for the room:" << endl;
            cout << "Please enter the length of the room: ";

            cin >> length;
        }

        // If the input is received as a valid int, attempt to save it
        valid = room.setLength(length);

        // If it cannot be saved to the house, reprompt
        if (!valid) {
            cout << "The length of the room entered was invalid.";
            cout << "Please enter the length of the room: ";

            cin >> length;
        }
    }

    // Prompt the user for the width of the room
    cout << "Please enter the width of the room: ";
    cin >> width;
    valid = false; // Reset flow variable

    // Continue asking until a valid width is entered.
    while (!valid) {
        // Check that the input is correct (Derived from code written by Dr. Poole.)
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "You must enter a numeric width for the room:" << endl;
            cout << "Please enter the width of the room: ";

            cin >> width;
        }

        // If the input is received as a valid int, attempt to save it
        valid = room.setWidth(width);

        // If it cannot be saved to the house, reprompt
        if (!valid) {
            cout << "The width of the room entered was invalid.";
            cout << "Please enter the width of the room: ";

            cin >> width;
        }
    }

    // Prompt the user for the height of the room
    cout << "Please enter the height of the room: ";
    cin >> height;
    valid = false; // Reset flow variable

    // Continue asking until a valid height is entered.
    while (!valid) {
        // Check that the input is correct (Derived from code written by Dr. Poole.)
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "You must enter a numeric height for the room:" << endl;
            cout << "Please enter the height of the room: ";

            cin >> height;
        }

        // If the input is received as a valid int, attempt to save it
        valid = room.setHeight(height);

        // If it cannot be saved to the house, reprompt
        if (!valid) {
            cout << "The height of the room entered was invalid.";
            cout << "Please enter the height of the room: ";

            cin >> height;
        }
    }

    // Prompt the user for the number of coats for the room
    cout << "Please enter the number of coats for the room: ";
    cin >> coats;
    valid = false; // Reset flow variable

    // Continue asking until a valid number of coats is entered.
    while (!valid) {
        // Check that the input is correct (Derived from code written by Dr. Poole.)
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "You must enter a numeric number of coats for the room:" << endl;
            cout << "Please enter the number of coats for the room: ";

            cin >> coats;
        }

        // If the input is received as a valid int, attempt to save it
        valid = room.setCoats(coats);

        // If it cannot be saved to the house, reprompt
        if (!valid) {
            cout << "The number of coats for the room entered was invalid.";
            cout << "Please enter the number of coats for the room: ";

            cin >> coats;
        }
    }

    // Try to add a room
    canAddRoom = house.addRoom(room);

    // If the maximum number of rooms has been reached, alert the user
    if (!canAddRoom) {
        cout << "The maximum number of rooms has been reached." << endl;
    }
}

/*
* Prompt the user asking if the invoice should
* be written to a file and save it if requested.
* Parameters:
* house - The House to use for the invoice
*/
void saveToFileOption(House& house) {
    string filename;
    char toSave{ 'y' };
    // Prompt the user for the height of the room
    cout << "Enter 'Y' to save your invoice: ";
    cin >> toSave;

    // Check that the input is correct (Derived from code written by Dr. Poole.)
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "You must enter a single character:" << endl;
        cout << "Enter 'Y' to save your invoice: ";

        cin >> toSave;
    }

    // If the user entered a Y, save the invoice
    if (toSave == 'y' || toSave == 'Y') {
        filename = house.getOwnerName() + ".txt";
        ofstream file(filename);

        printInvoice(file, house);
    }
    
    cout << "\n\n";
}

/*
* Calculate the labor costs given the number of coats of paint.
* Parameters:
* coats - The number of coats the laborers will paint.
*/
inline double calcLabor(int coats) {
    return coats * PAINTER_HOURLY_RATE;
}

/*
* Calculate the cost for paint the number of 1 gallon
* paint cans.
* Parameters:
* cans - The number of 1 gallon cans of paint needed for a room
*/
inline double calcRoomTotal(double cans) {
    return cans * PAINT_COST;
}

/*
* Calculate the cost of traveling to the client
* Parameters:
* distance - The distance from the client in miles
*/
inline double calcTravelCost(double distance) {
    return distance * MILEAGE_COST;
}

/*
* Print the invoice to the given stream.
* Pass cout to print to the console or an 
* ofstream to save to a file.
* Parameters:
* stream - A stream to output to
* house - The House to use for generating data
*/
void printInvoice(ostream& stream, House house) {
    double laborTotal{ 0 };
    double productTotal{ 0 };
    double travelTotal{ 0 };
    double total{ 0 };
    double cans{ 0 };
    double amount{ 0 };

    // Print the header
    stream << "***********************************************************" << endl;
    stream << house.getOwnerName() << endl;
    stream << "Final Invoice" << endl;
    stream << "***********************************************************" << endl;
    stream << endl;
    stream << "WePaintHouses LLC." << endl;
    stream << "4040 Painting Pl." << endl;
    stream << "Scranton, PA 18447" << endl;
    stream << "434-867-5309" << endl;
    stream << "WePaintHousesLLC.com" << endl;
    stream << endl;
    stream << "Billed to:\t" << house.getOwnerName() << endl;
    stream << endl;

    // Print labor charges
    stream << "-----------------------------------------------------------" << endl;
    stream << "                      Labor Charges                        " << endl;
    stream << "                      -------------                        " << endl;
    stream << "Rooms          Number of coats    Hourly Rate         Total" << endl;
    stream << left << setw(15) << house.getNumberOfRooms() << right
        << setw(15) << house.getTotalNumOfCoats()
        << setw(15) << setprecision(2) << fixed << PAINTER_HOURLY_RATE
        << setw(14) << setprecision(2) << fixed << calcLabor(house.getTotalNumOfCoats());
    stream << endl;

    // Print product charges
    stream << "                     Product Charges                       " << endl;
    stream << "                     ---------------                       " << endl;
    stream << "Room #            Paint Cans      Unit Cost          Amount" << endl;
    // Loop through the rooms and print an entry for each
    for (int i = 0; i < house.getNumberOfRooms(); i++) {
        cans = house.getRoomById(i).calcGallonsOfPaint();
        amount = calcRoomTotal(cans);
        productTotal += amount;
        stream << left << setw(15) << i+1;
        stream << right << setprecision(2) << fixed << setw(13) << cans;
        stream << right << setprecision(2) << fixed << setw(15) << PAINT_COST;
        stream << right << setprecision(2) << fixed << setw(16) << amount;
        stream << endl;
    }
    stream << "Total Product Charges:" 
        << right << setw(37) << setprecision(2) << fixed << productTotal << endl;
    
    // Print travel costs
    travelTotal = calcTravelCost(house.getDistance());
    stream << "                     Travel Charges                        " << endl;
    stream << "                     --------------                        " << endl;
    stream << "Mileage                            Rate Per Mile      Total" << endl;
    stream << left << setw(10) << house.getDistance();
    stream << right << setprecision(2) << fixed << setw(38) << MILEAGE_COST;
    stream << right << setprecision(2) << fixed << setw(11) << travelTotal;
    stream << endl;

    // Print total costs
    total = laborTotal + productTotal + travelTotal;
    stream << endl;
    stream << "-----------------------------------------------------------" << endl;
    stream << endl;
    stream << "Final Total:" << setw(47) << setprecision(2) << fixed << total << endl;
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
