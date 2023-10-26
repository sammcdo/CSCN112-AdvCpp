// Lab 5: Secure Messaging System
// Name: Sam McDowell
// Date: 10/25/2023

#include <iostream>
#include <fstream>
#include "Message.h"

using namespace std;

// Function Prototypes
void printMenu();
int getSelection();
string askForFile();
string askForKey();
void processFile(string filename, Message* message, bool isEncrypting);
void feedMessage(istream& file, Message* message, bool isEncrypting);
void wait();

// Global Variables
const int MAX_ARRAY_SIZE = 1000;


int main() {
    // Initialize variables
    Message* message{ NULL };
    bool shouldExit{ false };
    bool isEncrypting{ false };
    string key;
    int selection;
    string filename;

    // Print a title
    cout << "WePaintHouses Secure Messaging System\n" << endl;

    // Mainloop, continue until 3 is pressed
    while (!shouldExit) {
        // Show the menu and reset the flow variables
        printMenu();
        isEncrypting = false;

        // Get a menu selection
        selection = getSelection();

        // Based on the selection, execute their choice
        switch (selection) {
        case 1:
            // Encryption and decryption is the same code but change the flag
            isEncrypting = true;
        case 2:
            // Ask for a file to open
            cout << "To begin create a text file to store your message." << endl;
            filename = askForFile();

            // Ask for the encryption key
            key = askForKey();

            // Create the new message
            message = new Message(key);

            // Fill the message with processed words
            processFile(filename, message, isEncrypting);

            // Save the file
            cout << "Saving file..." << endl;
            filename = askForFile();
            message->makeFile(filename);

            // Show the user the message
            cout << "Final message:\n" << endl;
            message->showWords();
            cout << "\n\n";
            break;
        case 3:
            // Exit the mainloop
            shouldExit = true;
            break;
        default:
            // This should not happen but default behavior is to exit
            cout << "Invalid input, exiting";
            shouldExit = true;
            break;
        }
    }

    // Wait for input before exiting
    wait();

    return 0;
}

/*
* Print the main menu
*/
void printMenu() {
    cout << "************************" << endl;
    cout << "    Vigenere Cypher     " << endl;
    cout << "       Main Menu        " << endl;
    cout << endl;
    cout << "1 - Encrypt File" << endl;
    cout << "2 - Decrypt File" << endl;
    cout << "3 - Quit" << endl;
}


/*
* Get the user's choice of the menu items.
* This will prompt the user and wait for an input from 1-3
* Return:
* The user selection as an int
*/
int getSelection() {
    int temp{ 0 };

    // Prompt the user
    cout << "Please select your menu choice: ";
    cin >> temp;

    // Check that the input is correct (Derived from code written by Dr. Poole.)
    while (cin.fail() || temp < 1 || temp > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "That number is not an option." << endl;
        cout << "Please select your menu choice: ";

        cin >> temp;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return temp;
}

/*
* Prompt the user for a filename
* Return:
* The filename selected
*/
string askForFile() {
    string filename;

    cout << "Enter the filename:" << endl;

    getline(cin, filename);

    return filename;
}

/*
* Ask for a cypher key
* Return:
* The key they entered
*/
string askForKey() {
    string key {""};
    cout << "Please enter a secret key:" << endl;
    cin >> key;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return key;
}

/*
* Opens the filename given and cyphers the contents line by line
* based on whether it is encrypting or decrypting
* Params:
* filename - The filename to open
* message - The message to add words to
* isEncrypting - true for encryption, false for decryption
*/
void processFile(string filename, Message* message, bool isEncrypting) {
    // Open the file
    ifstream file(filename);

    if (file.good()) { // File does exist
        // Feed the message
        feedMessage(file, message, isEncrypting);
    }
    else { // File does not exist
        cout << "File does not exist" << endl;
    }
}

/*
* Feed a message with tokenized lines until the input istream fails
* Params:
* file - The istream to read lines from until failure
* message - The message object to store tokenized words in
* isEncrypting - true for encryption, false for decryption
*/
void feedMessage(istream& file, Message* message, bool isEncrypting) {
    char line[MAX_ARRAY_SIZE];

    // Attempt to read the first line
    file.getline(line, MAX_ARRAY_SIZE);

    // Repeat until fail or EOF
    while (!file.fail()) {

        // Initialize tokenization variables
        char* token = NULL;
        char* context = NULL;
        char delims[] = " .,\t\n";

        // Get the first token
        token = strtok_s(line, delims, &context);

        // Repeat while there are still tokens available
        while (token != NULL) {
            // Encrypt or decrypt the token
            if (isEncrypting) {
                message->encrypt(token);
            }
            else {
                message->decrypt(token);
            }

            // Prepare the next token
            token = strtok_s(NULL, delims, &context);
        }

        file.getline(line, MAX_ARRAY_SIZE);
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