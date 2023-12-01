// Lab 7: Inheritance and Operator Overloading
// Sam McDowell
// 11/17/2023

#include <iostream>
#include <string>
#include "Course.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

void printTitle();
void getCourseInfo(Course* course);
void printMenu();
char getMenuSelection();
void addInstructor(Course* course);
void addStudent(Course* course);
void listCourse(Course* course);

void tokenizeDate(char* cDate, int& month, int& day, int& year);
void wait();

/*
* The main program
*/
int main() {
    Course course;

    bool shouldExit{ false };
    char selection{ ' ' };


    // Print the program title
    printTitle();
    cout << "\n\n";

    // Get the course info from the user
    getCourseInfo(&course);
    cout << "\n\n";

    // Print the menu and start the main loop
    do {
        // Print the menu
        printMenu();
        cout << endl;

        // Get a valid menu selection
        selection = getMenuSelection();
        cout << "\n\n";

        // Respond to the option they picked
        switch (selection) {
        case 'I':
        case 'i':
            // They would like to add an instructor
            if (course.getFaculty() == NULL) {       // No instructor has been added
                addInstructor(&course);
            }
            else {                                   // The instructor has already been added, alert the user
                cout << "Faculty is already assigned." << endl;
            }
            break;
        case 'S':
        case 's':
            // They would like to add a student
            if (!course.isClassFull()) {            // The class is not full
                addStudent(&course);
            }
            else {                                  // The class is full, alert the user
                cout << "Class is full. No more students can be added." << endl;
            }
            break;
        case 'L':
        case 'l':
            // List the course info
            listCourse(&course);
            break;
        case 'Q':
        case 'q':
            // Exit the loop
            shouldExit = true;
            break;
        default:
            // They did not enter something from the menu
            cout << "Invalid Menu Selection, please try again." << endl;
            break;
        }

        cout << "\n\n";

    } while (!shouldExit);

    // Wait for user input to exit
    wait();

    return 0;
}

/*
* Print a title for the program
*/
void printTitle() {
    cout << "*************************************************" << endl;
    cout << "               Course Registration               " << endl;
    cout << "*************************************************" << endl;
    cout << endl;
}

/*
* Ask the user for the course info
* Params:
* course - The course to update
*/
void getCourseInfo(Course* course) {
    string title;
    bool valid{ false };
    int cap;

    // Get the course name
    cout << "Enter a name for your Course: ";
    getline(cin, title);

    course->setName(title);

    cout << "\n\n";

    // Get the number of students with error checking
    while (!valid) {
        cout << "Please enter the Course capacity: ";
        cin >> cap;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            valid = false;
        }
        else {
            valid = course->setCapacity(cap);
        }

        if (!valid) {
            cout << "Invalid Course capacity. Please enter a positive number." << endl;
        }
    }

    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
* Print the menu
*/
void printMenu() {
    cout << "          Main Menu           " << endl;
    cout << "  I -- Add Instructor         " << endl;
    cout << "  S -- Add Student            " << endl;
    cout << "  L -- List Course Information" << endl;
    cout << "  Q -- Quit                   " << endl;
}

/*
* Get the users selection from the menu
* Return:
* A char representing their menu selection
*/
char getMenuSelection() {
    char selection;

    cout << "Selection: ";
    cin >> selection;

    // Make sure they enter a char
    while (cin.fail()) {
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
* Prompt the user for each item to make an instructor
* and add them to the course.
* Params:
* course - The course to add the instructor to
*/
void addInstructor(Course* course) {
    string temp;
    int tempM, tempD, tempY;
    double tempSal;
    bool valid{ false };
    Faculty* instructor = new Faculty();

    cout << "Creating a Faculty Member:" << endl;
    cout << endl;

    // Get the ID
    cout << "ID: ";
    getline(cin, temp);
    instructor->setID(temp);

    // Get the first name
    cout << "First Name: ";
    getline(cin, temp);
    instructor->setFirstName(temp);

    // Get the last name
    cout << "Last Name: ";
    getline(cin, temp);
    instructor->setLastName(temp);

    // Get the birthday
    cout << "Birth date (mm/dd/yyy): ";
    getline(cin, temp);
    tokenizeDate(&temp[0], tempM, tempD, tempY);
    Date bday;
    bday.setDate(tempM, tempD, tempY);
    instructor->setBirthday(bday);

    // Get the title
    cout << "Title: ";
    getline(cin, temp);
    instructor->setTitle(temp);

    // Get the rank
    cout << "Rank: ";
    getline(cin, temp);
    instructor->setRank(temp);

    // Get the salary with error checking
    while (!valid) {
        cout << "Salary: ";
        cin >> tempSal;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }
        else {
            valid = instructor->setSalary(tempSal);
        }

        if (!valid) {
            cout << "Invalid Salary. Please enter a positive number." << endl;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Get the date of hire
    cout << "Date of Hire (mm/dd/yyy): ";
    getline(cin, temp);
    tokenizeDate(&temp[0], tempM, tempD, tempY);
    Date hired;
    hired.setDate(tempM, tempD, tempY);
    instructor->setDateHired(hired);

    // Assign the faculty to the course
    course->setFaculty(instructor);
}

/*
* Add a student to the course
* Params:
* course - The course to add the student to
*/
void addStudent(Course* course) {
    string temp;
    int tempM, tempD, tempY;
    double tempGPA;
    bool valid{ false };
    Student student;

    cout << "Creating a Student:" << endl;
    cout << endl;

    // Get the ID
    cout << "ID: ";
    getline(cin, temp);
    student.setID(temp);
    
    // Get the first name
    cout << "First Name: ";
    getline(cin, temp);
    student.setFirstName(temp);

    // Get the last name
    cout << "Last Name: ";
    getline(cin, temp);
    student.setLastName(temp);

    // Get the birthday
    cout << "Birth date (mm/dd/yyy): ";
    getline(cin, temp);
    tokenizeDate(&temp[0], tempM, tempD, tempY);
    Date bday;
    bday.setDate(tempM, tempD, tempY);
    student.setBirthday(bday);
    
    // Get their major
    cout << "Major: ";
    getline(cin, temp);
    student.setMajor(temp);

    // Get their level
    cout << "Level (Freshman, Sophomore, Junior, Senior): ";
    getline(cin, temp);
    student.setLevel(temp);
    
    // Get the GPA with error checking
    while (!valid) {
        cout << "GPA: ";
        cin >> tempGPA;

        valid = true;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }
        else {
            valid = student.setGPA(tempGPA);
        }

        if (!valid) {
            cout << "Invalid GPA. Please enter a positive number." << endl;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Get the date of enrollment
    cout << "Date of Enrollment (mm/dd/yyy): ";
    getline(cin, temp);
    tokenizeDate(&temp[0], tempM, tempD, tempY);
    Date enrolled;
    enrolled.setDate(tempM, tempD, tempY);
    student.setDateEnrolled(enrolled);

    // Add the student to the course
    course->addStudent(student);

}

/*
* Print the course to the console
*/
void listCourse(Course* course) {
    cout << *course;
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