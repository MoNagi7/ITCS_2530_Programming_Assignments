
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

enum ActivityLevel
{
	Low,
	Moderate,
	High
};

// Store information about an individual soccer session.
struct ActivitySession
{
	string activityName;
	double hours;
    ActivityLevel level;
};

//Declare Functions
void displaySoccerSessions(const ActivitySession sessions[], int size);

// Change the console text color.
void changeConsoleColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

// Display the welcome message.
void displayBanner()
{
    cout << "Welcome to My Sports Program!\n\n";
}

// Ask the user for their name and check the answer.
void getPlayerName(string& playerName)
{
    cout << "What is your full name? ";
    getline(cin, playerName);

    while (playerName == "")
    {
        cout << "Please enter your name: ";
        getline(cin, playerName);
    }
}

// Get and validate soccer hours.
void getSoccerHours(double& soccerHours)
{
    cout << "How many hours do you play soccer each week? ";
    cin >> soccerHours;

    while (cin.fail() || soccerHours < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid soccer hours. Please enter a non-negative number: ";
        cin >> soccerHours;
    }
}

// Get and validate volleyball hours.
void getVolleyballHours(int& volleyballHours)
{
    cout << "How many hours do you play volleyball each week? ";
    cin >> volleyballHours;

    while (cin.fail() || volleyballHours < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid volleyball hours. Please enter a non-negative whole number: ";
        cin >> volleyballHours;
    }
}

// Get and validate the number of days played.
void getDaysPlayed(int& daysPlayed)
{
    cout << "How many days do you play sports each week? ";
    cin >> daysPlayed;

    while (cin.fail() || daysPlayed < 0 || daysPlayed > 7)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid days. Please enter a number from 0 to 7: ";
        cin >> daysPlayed;
    }
}

// Calculate total soccer hours using array of sessions.
double calculateSoccerHours(const ActivitySession sessions[], int size)
{
    double total = 0.0;

    for (int i = 0; i < size; i++)
    {
        total += sessions[i].hours;
    }
    return total;
}

// Display individual soccer session hours.

void displaySoccerSessions(const ActivitySession sessions[], int size)
{
    cout << "\nSoccer Practice Sessions\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Session " << (i + 1)
            << ": " << fixed << setprecision(1)
            << sessions[i].hours << " hours"
            << " | Level: ";

        switch (sessions[i].level)
        {
        case Low:
            cout << "Low";
            break;

        case Moderate:
            cout << "Moderate";
            break;

        case High:
            cout << "High";
            break;
        }

        cout << "\n";
    }
}

// Calculate the total weekly sports hours.
double calculateTotalHours(double soccerHours, int volleyballHours)
{
    return soccerHours + volleyballHours;
}

// Determine User's weekly sports activity level
ActivityLevel determineActivityLevel(double totalHours)
{
    if (totalHours < 5)
    {
        return Low;
    }
    else if (totalHours <= 10)
    {
        return Moderate;
    }
    else
    {
        return High;
    }
}

// Display the sports menu.
void displayMenu()
{
    cout << "\nSports Menu\n";
    cout << "1. View Sports Summary\n";
    cout << "2. Compare Soccer and Volleyball Hours\n";
    cout << "3. Check Weekly Activity Level\n";
    cout << "4. Exit\n";
}

// Show the formatted sports summary.
void displaySummary(string playerName, double soccerHours,
    int volleyballHours, int daysPlayed, double totalHours,
    const ActivitySession sessions[], int size)
{
    cout << "\nMy Sports Summary\n";
    cout << "Player: " << playerName << "\n\n";

    cout << left << setw(25) << "Activity"
        << right << setw(12) << "Hours/Days" << "\n";
    cout << "-------------------------------------\n";

    cout << left << setw(25) << "Soccer Hours"
        << right << setw(12) << fixed << setprecision(1) << soccerHours << "\n";
    cout << left << setw(25) << "Volleyball Hours"
        << right << setw(12) << volleyballHours << "\n";
    cout << left << setw(25) << "Days Played"
        << right << setw(12) << daysPlayed << "\n";
    cout << left << setw(25) << "Total Hours"
        << right << setw(12) << totalHours << "\n";

	//Display individual soccer session hours.
	displaySoccerSessions(sessions, size);

    cout << "\nKeep having fun and staying active!\n";

    // Show the total sports hours for three weeks.
    cout << "\nThree-Week Sports Hours Projection\n";
    for (int week = 1; week <= 3; week++)
    {
        cout << "Total hours after week " << week
            << ": " << totalHours * week << "\n";
    }
}

// Save the same formatted sports summary to a text file.
void saveReport(string playerName, double soccerHours,
    int volleyballHours, int daysPlayed, double totalHours,
    const ActivitySession sessions[], int size)
{
    ofstream reportFile("report.txt");

    if (!reportFile)
    {
        cout << "Could not save report.txt.\n";
        return;
    }

    reportFile << "My Sports Summary\n";
    reportFile << "Player: " << playerName << "\n\n";

    reportFile << left << setw(25) << "Activity"
        << right << setw(12) << "Hours/Days" << "\n";
    reportFile << "-------------------------------------\n";
    reportFile << left << setw(25) << "Soccer Hours"
        << right << setw(12) << fixed << setprecision(1) << soccerHours << "\n";
    reportFile << left << setw(25) << "Volleyball Hours"
        << right << setw(12) << volleyballHours << "\n";
    reportFile << left << setw(25) << "Days Played"
        << right << setw(12) << daysPlayed << "\n";
    reportFile << left << setw(25) << "Total Hours"
        << right << setw(12) << totalHours << "\n";
    // Save inividual soccer sessions
	reportFile << "\nSoccer Sessions\n";

    for (int i = 0; i < size; i++)
    {
        reportFile << "Session " << (i + 1)
            << ": " << fixed << setprecision(1)
            << sessions[i].hours << " hours\n";
    }

    reportFile << "\nKeep having fun and staying active!\n";

    reportFile.close();
    cout << "Your sports summary was saved to report.txt.\n";
}

// Get and validate information for each soccer session.
void getSoccerSessions(ActivitySession sessions[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // Identify the activity.
        sessions[i].activityName = "Soccer";

        // Get and validate session hours.
        cout << "Enter the number of hours for soccer session "
            << (i + 1) << ": ";
        cin >> sessions[i].hours;

        while (cin.fail() || sessions[i].hours < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a non-negative number for soccer session "
                << (i + 1) << ": ";
            cin >> sessions[i].hours;
        }

        // Assign the activity level based on session hours.
        if (sessions[i].hours < 1)
        {
            sessions[i].level = Low;
        }
        else if (sessions[i].hours <= 2)
        {
            sessions[i].level = Moderate;
        }
        else
        {
            sessions[i].level = High;
        }
    }
}

int main()
{
    double soccerHours;
    int volleyballHours;
    int daysPlayed;
    double totalHours;
    string playerName;
    int menuChoice;
    const int max_Sessions = 5;
    ActivitySession soccerSessions[max_Sessions] = {};

    // Change the text color and display the welcome message.
    changeConsoleColor();
    displayBanner();

    // Collect and validate the user's information.
    getPlayerName(playerName);
	getSoccerSessions(soccerSessions, max_Sessions);
    getVolleyballHours(volleyballHours);
    getDaysPlayed(daysPlayed);

    // Calculate the total hours spent playing sports.
	soccerHours = calculateSoccerHours(soccerSessions, max_Sessions);
    totalHours = calculateTotalHours(soccerHours, volleyballHours);

    // Repeat the menu until the user chooses Exit.
    do
    {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> menuChoice;

        // Keep asking until the user enters a valid choice.
        while (cin.fail() || menuChoice < 1 || menuChoice > 4)
        {
            cout << "Invalid choice. Please enter 1, 2, 3, or 4.\n";

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }

            cout << "Enter your choice (1-4): ";
            cin >> menuChoice;
        }

        // Check which option the user selected.
        switch (menuChoice)
        {
        case 1:
            cout << "\nYou selected View Sports Summary.\n";
            displaySummary(playerName, soccerHours, volleyballHours,
                daysPlayed, totalHours, soccerSessions, max_Sessions);
            break;

        case 2:
            cout << "\nYou selected Compare Sports Hours.\n";

            if (soccerHours > volleyballHours || soccerHours == volleyballHours)
            {
                cout << "You play soccer as much as or more than volleyball.\n";
            }
            else
            {
                cout << "You play more volleyball than soccer.\n";
            }
            break;

        case 3:
        {
            cout << "\nYou selected Check Weekly Activity Level.\n";

            ActivityLevel weeklyActivity = determineActivityLevel(totalHours);

            switch (weeklyActivity)
            {
            case Low:
                cout << "Your weekly activity level is LOW.\n";
                break;

            case Moderate:
                cout << "Your weekly activity level is MODERATE.\n";
                break;

            case High:
                cout << "Your weekly activity level is HIGH.\n";
                break;
            }

            if (daysPlayed >= 3 && totalHours >= 5)
            {
                cout << "You met your weekly sports activity goal.\n";
            }
            else
            {
                cout << "You did not meet your weekly sports activity goal.\n";
            }

            break;
        }

        case 4:
            cout << "\nThank you for using My Sports Program!\n";
            break;
        }

    } while (menuChoice != 4);

    // Save the sports summary to a text file.
    saveReport(playerName, soccerHours, volleyballHours, daysPlayed, totalHours, soccerSessions, max_Sessions);

    return 0;
}
