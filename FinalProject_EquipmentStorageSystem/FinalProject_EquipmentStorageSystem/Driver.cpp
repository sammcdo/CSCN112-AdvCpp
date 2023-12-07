// FinalProject_EquipmentStorageSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Ladder.h"
#include "Scaffold.h"
#include "StorageUnit.h"
#include "StorageUnit.cpp"
#include "Equipment.h"

#include "InvalidIdException.h"

using namespace std;

void printMenu();
int getMenuSelection();

int getWhichUnit();

void tokenizeDate(char* cDate, int& month, int& day, int& year);

template <class T>
void updateStorageUnit(StorageUnit<T>& unit);

template <class T>
void createEquipmentForUnit(int equipmentType, T& equipment);

void setUpLadder(Ladder& ladder);
void setUpScaffold(Scaffold& scaffold);

template <class T>
void addToStorageUnit(StorageUnit<T>& unit, T equipment);

void wait();


int main() {
    StorageUnit<Ladder> ladders;
    StorageUnit<Scaffold> scaffolds;
    
    bool isFinished{ false };
    int selection{ 0 };
    int whichUnit{ 0 };
    string seek;

    // Main loop
    do {
        // Print the menu and get the user's selection
        printMenu();
        selection = getMenuSelection();

        // Decide what to do based on the selection
        switch (selection) {
        // Modify a storage container
        case 1:
            // Prompt which unit to edit and make the changes
            whichUnit = getWhichUnit();
            if (whichUnit == 1) {
                updateStorageUnit(ladders);
            }
            else {
                updateStorageUnit(scaffolds);
            }

            // Wait for user to hit enter and then clear the screen
            wait();
            system("cls");
            break;
        // Add an item to storage
        case 2:
            // Prompt which unit and handle accordingly
            whichUnit = getWhichUnit();
            if (whichUnit == 1) {
                Ladder temp;
                // Fill out generic equipment details
                createEquipmentForUnit(whichUnit, temp);
                // Add ladder details
                setUpLadder(temp);
                // Add the equipment to storage
                addToStorageUnit(ladders, temp);
                // Print the new inventory
                ladders.printInventory();
            }
            else {
                Scaffold temp;
                // Fill out generic equipment details
                createEquipmentForUnit(whichUnit, temp);
                // Add scaffold details
                setUpScaffold(temp);
                // Add the equipment to storage
                addToStorageUnit(scaffolds, temp);
                // Print the new inventory
                scaffolds.printInventory();
            }
            // Wait for user and then clear the screen.
            wait();
            system("cls");
            break;
        // Remove an item from inventory by ID
        case 3:
            // Prompt which unit and handle accordingly
            whichUnit = getWhichUnit();
            cout << "Enter an ID to delete: ";
            cin >> seek;
            try {
                if (whichUnit == 1) {
                    // Remove an item from inventory and print the inventory
                    ladders.removeInventory(seek);
                    cout << "\nItem was removed.\n" << endl;
                    ladders.printInventory();
                }
                else {
                    // Remove an item from inventory and print the inventory
                    scaffolds.removeInventory(seek);
                    cout << "\nItem was removed.\n" << endl;
                    scaffolds.printInventory();
                }
                
            }
            catch (ItemNotFoundException& e) {
                cout << "An item with that ID does not exist" << endl;
            }

            // Wait for user interaction and clear
            cout << "\n\n";
            wait();
            system("cls");
            break;
        // Print the inventory
        case 4:
            // Print ladder inventory
            cout << "Ladder Inventory:" << endl;
            ladders.printInventory();

            cout << "\n\n";

            // Print scaffold inventory
            cout << "Scaffold Inventory:" << endl;
            scaffolds.printInventory();

            // Wait for user interaction and clear
            cout << "\n\n";
            wait();
            system("cls");
            break;
        // Exit the loop
        case 5:
            // change the sentinel to true
            isFinished = true;
            break;
        }


    } while (!isFinished);



    return 0;
}

/*
* Print the program menu
*/
void printMenu() {
    cout << "*********************************************************************" << endl;
    cout << "                            WePaintHouses                            " << endl;
    cout << "                       Equipment Storage System                      " << endl;
    cout << "*********************************************************************" << endl;
    cout << endl;
    cout << "\t1 - Update Storage Unit General Information" << endl;
    cout << "\t2 - Add Equipment to a Storage Unit" << endl;
    cout << "\t3 - Remove Equipment from a Storage Unit" << endl;
    cout << "\t4 - Print Equipment Inventory -- All Units" << endl;
    cout << "\t5 - Exit Program" << endl;
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
    while (cin.fail() || selection < 1 || selection > 5) {
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
* Get the unit that the user is going to modify
* Return:
* An int representing their choice
*/
int getWhichUnit() {
    cout << "Enter which storage unit you would like to modify:" << endl;
    cout << endl;
    cout << "1 - Ladders" << endl;
    cout << "2 - Scaffolds" << endl;
    cout << endl;


    int selection;

    cout << "Selection: ";
    cin >> selection;

    // Make sure they enter a valid int
    while (cin.fail() || selection < 1 || selection > 2) {
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
* Given a string, update the given month, day,
* and year variables with the times from the string.
*
* Courtesy of Dr. Poole.
* Params:
* cDate - A pointer to the first letter of the string
* month - The variable to save the month
* day - The variable to save the day
* year - The variable to save the year
*/
void tokenizeDate(char* cDate, int& month, int& day, int& year) {
    char seps[] = "/";
    char* token = NULL;
    char* next_token = NULL;
    token = NULL;
    next_token = NULL;

    // Establish string and get the tokens:
    token = strtok_s(cDate, seps, &next_token);
    month = atoi(token);

    token = strtok_s(NULL, seps, &next_token);
    day = atoi(token);

    token = strtok_s(NULL, seps, &next_token);
    year = atoi(token);
}

/*
* Update the information of a storage unit. This 
* includes prompting for the ID, width, height, length, 
* cost, contract date, auto-renew and humidity control
* Params:
* unit - The storage unit to modify
*/
template <class T>
void updateStorageUnit(StorageUnit<T>& unit) {
    string temp;
    float tempNum;
    bool valid{ false };
    char choice;

    // Print a short title
    cout << "Storage Unit General Information" << endl;
    cout << endl;
    cout << "Enter the ID of the Storage Unit: ";

    // Get the ID
    cin >> temp;
    unit.setUnitID(temp);

    // Get the description
    cout << "Enter the description of the Storage Unit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, temp);
    unit.setDescription(temp);

    // Get the length of the unit
    tempNum = -1;
    valid = false;
    cout << "Enter the length of the unit (in feet): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                unit.setLength(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric length." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the length of the unit (in feet): ";
            cin >> tempNum;
        }
        
    }

    // Get the width of the unit
    tempNum = -1;
    valid = false;
    cout << "Enter the width of the unit (in feet): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                unit.setWidth(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric width." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the width of the unit (in feet): ";
            cin >> tempNum;
        }

    }
    
    // Get the height of the unit
    tempNum = -1;
    valid = false;
    cout << "Enter the height of the unit (in feet): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                unit.setHeight(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric height." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the height of the unit (in feet): ";
            cin >> tempNum;
        }

    }

    // Get the cost of the unit
    tempNum = -1;
    valid = false;
    cout << "Enter the cost per month to rent the unit: ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                unit.setCostPerMonth(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric cost." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the cost per month to rent the unit: ";
            cin >> tempNum;
        }

    }

    // Get the date when the unit was rented
    while (true) {
        Date rented;
        int month, day, year;
        try {
            cout << "Enter the date rented (mm/dd/yyyy): ";
            cin >> temp;

            tokenizeDate(&temp[0], month, day, year);

            rented.setDate(day, month, year);

            unit.setRentalContractDate(rented);
            break;
        }
        catch (std::exception e) {
            cout << "Please enter a valid date." << endl;
            cin.clear();
        }
    }

    // Get whether it autorenews
    cout << "Does the contract auto-renew (Y or N): ";
    cin >> choice;
    while (cin.fail() || !(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')) {
        cout << "Please enter your choice again." << endl;
        cout << "Does the contract auto-renew (Y or N): ";
        cin >> choice;
    }
    if (choice == 'Y' || choice == 'y') {
        unit.setAutoRenew(true);
    }
    else {
        unit.setAutoRenew(false);
    }

    // Get whether it is humidity controlled
    cout << "Is the unit humidity controlled (Y or N): ";
    cin >> choice;
    while (cin.fail() || !(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')) {
        cout << "Please enter your choice again." << endl;
        cout << "Is the unit humidity controlled (Y or N): ";
        cin >> choice;
    }
    if (choice == 'Y' || choice == 'y') {
        unit.setAutoRenew(true);
    }
    else {
        unit.setAutoRenew(false);
    }

    cout << endl;
    cout << unit;
    cout << endl;
}

/*
* Create a generic piece of equipment to be stored in a storage unit.
* This includes the ID, cost, and date purchased
* Params:
* equipmentType - 1 for a Ladder, 2 for a Scaffold. This controls the title
* equipment - An object to modify with the basic information
*/
template <class T>
void createEquipmentForUnit(int equipmentType, T& equipment) {
    string temp;
    double tempNum;
    int tempInt;
    bool valid;

    // Print a menu
    if (equipmentType == 1) {
        cout << "Enter LADDER information" << endl;
    }
    else {
        cout << "Enter SCAFFOLD information" << endl;
    }

    cout << endl;

    // Get the ID
    cout << "Enter the ID of the item: ";
    cin >> temp;
    equipment.setID(temp);

    // Get the cost
    tempNum = -1;
    valid = false;
    cout << "Enter the original cost of the item: ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                equipment.setCost(tempNum);
                valid = true;
                break;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric cost." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the original cost of the item: ";
            cin >> tempNum;
        }

    }

    // Get the date purchased
    while (true) {
        Date rented;
        int month, day, year;
        try {
            cout << "Enter the date purchased (mm/dd/yyyy): ";
            cin >> temp;

            tokenizeDate(&temp[0], month, day, year);

            rented.setDate(day, month, year);

            equipment.setDatePurchased(rented);
            break;
        }
        catch (std::exception e) {
            cout << "Please enter a valid date." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    //Get the useful life
    // Get the cost
    tempInt = -1;
    valid = false;
    cout << "Enter the useful life of the item: ";
    cin >> tempInt;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                equipment.setUsefulLife(tempInt);
                valid = true;
                break;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive useful life." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the useful life of the item: ";
            cin >> tempInt;
        }

    }
}

/*
* Configure a ladder for storage.
* This includes height, style, and weight limit
* Params:
* ladder - The ladder to modify with the user's responses.
*/
void setUpLadder(Ladder& ladder) {
    string temp;
    double tempNum;
    bool valid;

    // Get the height
    tempNum = -1;
    valid = false;
    cout << "Enter the height of the ladder (in feet): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                ladder.setHeight(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric height." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the height of the ladder (in feet): ";
            cin >> tempNum;
        }

    }

    // Get the style of the ladder
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the style of the ladder: ";
    getline(cin, temp);
    ladder.setStyle(temp);

    // Get the weight limit of the ladder
    tempNum = -1;
    valid = false;
    cout << "Enter the maximum weight that the ladder can support (in pounds): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                ladder.setWeightLimit(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric weight." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the maximum weight that the ladder can support (in pounds): ";
            cin >> tempNum;
        }

    }
}

/*
* Configure a scaffold for storage.
* This includes length, width, height, and weight limit.
* Params:
* scaffold - The scaffold to modify with the user's responses.
*/
void setUpScaffold(Scaffold& scaffold) {
    string temp;
    double tempNum;
    bool valid;

    // Get the length
    tempNum = -1;
    valid = false;
    cout << "Enter the length of the scaffold (in feet): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                scaffold.setLength(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric length." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the length of the scaffold (in feet): ";
            cin >> tempNum;
        }

    }

    // Get the width
    tempNum = -1;
    valid = false;
    cout << "Enter the width of the scaffold (in feet): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                scaffold.setWidth(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric width." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the width of the scaffold (in feet): ";
            cin >> tempNum;
        }

    }

    // Get the height
    tempNum = -1;
    valid = false;
    cout << "Enter the height of the scaffold (in feet): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                scaffold.setHeight(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric height." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the height of the scaffold (in feet): ";
            cin >> tempNum;
        }

    }

    // Get the weight limit
    tempNum = -1;
    valid = false;
    cout << "Enter the weight limit of the scaffold (in lbs): ";
    cin >> tempNum;
    while (cin.fail() || !valid) {
        if (!cin.fail()) {
            try {
                scaffold.setWeightLimit(tempNum);
                valid = true;
            }
            catch (NegativeNumberException& e) {
                valid = false;
            }
        }
        if (!valid) {
            cout << "Please enter a positive numeric limit." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the weight limit of the scaffold (in lbs): ";
            cin >> tempNum;
        }

    }
}

/*
* Add the given equipment to the given storage container.
* It ensures there are no duplicate IDs
* Params:
* unit - The storage unit to put the item in
* equipment - The piece of equipment to store
*/
template <class T>
void addToStorageUnit(StorageUnit<T>& unit, T equipment) {
    string temp;

    // Repeat until a unique ID has been entered.
    while (true) {
        try {
            // Add the unit to storage
            unit.addEquipment(equipment);
            break;
        }
        catch (InvalidIdException& e) {
            cout << "An item with that ID already exists." << endl;
            cout << "Please enter a new ID: ";
            cin >> temp;

            equipment.setID(temp);
        }
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