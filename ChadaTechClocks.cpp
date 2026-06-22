/*
    Name: Nicholas Bucks
    Project: Chada Tech Clocks
    Course: CS 210

    This program displays a 12-hour and 24-hour clock side by side.
    The user can add one hour, one minute, or one second to both clocks.
*/

#include <iostream>
#include <string>

using namespace std;

// Adds one hour and wraps back to 0 after 23
void addOneHour(int& hour) {
    hour = (hour + 1) % 24;
}

// Adds one minute and adds an hour if minutes go past 59
void addOneMinute(int& hour, int& minute) {
    minute++;

    if (minute > 59) {
        minute = 0;
        addOneHour(hour);
    }
}

// Adds one second and adds a minute if seconds go past 59
void addOneSecond(int& hour, int& minute, int& second) {
    second++;

    if (second > 59) {
        second = 0;
        addOneMinute(hour, minute);
    }
}

// Returns a two-digit number format for hours, minutes, and seconds
string twoDigitFormat(int number) {
    if (number < 10) {
        return "0" + to_string(number);
    }

    return to_string(number);
}

// Displays both the 12-hour and 24-hour clocks side by side
void displayClocks(int hour, int minute, int second) {
    int twelveHour;
    string meridiem;

    if (hour == 0) {
        twelveHour = 12;
        meridiem = "A M";
    }
    else if (hour < 12) {
        twelveHour = hour;
        meridiem = "A M";
    }
    else if (hour == 12) {
        twelveHour = 12;
        meridiem = "P M";
    }
    else {
        twelveHour = hour - 12;
        meridiem = "P M";
    }

    cout << endl;
    cout << "**************************     **************************" << endl;
    cout << "*      12-Hour Clock     *     *      24-Hour Clock     *" << endl;
    cout << "*      "
        << twoDigitFormat(twelveHour) << ":"
        << twoDigitFormat(minute) << ":"
        << twoDigitFormat(second) << " " << meridiem
        << "      *     *        "
        << twoDigitFormat(hour) << ":"
        << twoDigitFormat(minute) << ":"
        << twoDigitFormat(second)
        << "        *" << endl;
    cout << "**************************     **************************" << endl;
    cout << endl;
}

// Displays the user menu
void displayMenu() {
    cout << "**************************" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << "**************************" << endl;
}

// Gets the initial time from the user
void getInitialTime(int& hour, int& minute, int& second) {
    cout << "Enter the initial hour in 24-hour format between 0 and 23: ";
    cin >> hour;

    cout << "Enter the initial minute between 0 and 59: ";
    cin >> minute;

    cout << "Enter the initial second between 0 and 59: ";
    cin >> second;

    while (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        cout << endl;
        cout << "Invalid time entered. Please try again." << endl;

        cout << "Enter the initial hour in 24-hour format between 0 and 23: ";
        cin >> hour;

        cout << "Enter the initial minute between 0 and 59: ";
        cin >> minute;

        cout << "Enter the initial second between 0 and 59: ";
        cin >> second;
    }
}

// Runs the main menu loop
void mainMenu() {
    int hour;
    int minute;
    int second;
    int userChoice = 0;

    getInitialTime(hour, minute, second);

    while (userChoice != 4) {
        displayClocks(hour, minute, second);
        displayMenu();

        cout << "Enter your choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            addOneHour(hour);
        }
        else if (userChoice == 2) {
            addOneMinute(hour, minute);
        }
        else if (userChoice == 3) {
            addOneSecond(hour, minute, second);
        }
        else if (userChoice == 4) {
            cout << "Program ended." << endl;
        }
        else {
            cout << "Invalid choice. Please enter 1, 2, 3, or 4." << endl;
        }
    }
}

int main() {
    mainMenu();

    return 0;
}