
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    double  soccerHours;
    int volleyballHours;
    int daysPlayed;
    double  totalHours;
    string playerName;

    // Ask the user three questions about sports.
    cout << "Welcome to My Sports Program!\n\n";

    cout << "What is your full name? ";
    getline(cin, playerName);

    cout << "How many hours do you play soccer each week? ";
    cin >> soccerHours;

    // Check if the soccer hours are valid.
    if (cin.fail() || soccerHours < 0)
    {
        cout << "Invalid soccer hours. Please enter a positive number.\n";
        return 1;
    }

    cout << "How many hours do you play volleyball each week? ";
    cin >> volleyballHours;

    // Check if the volleyball hours are valid.
    if (cin.fail() || volleyballHours < 0)
    {
        cout << "Invalid volleyball hours. Please enter a non-negative whole number.\n";
        return 1;
    }

    cout << "How many days do you play sports each week? ";
    cin >> daysPlayed;

    // Check if the days played are valid.
    if (cin.fail() || daysPlayed < 0 || daysPlayed > 7)
    {
        cout << "Invalid days. Please enter a number from 0 to 7.\n";
        return 1;
    }

    // Calculate the total hours spent playing sports.
    totalHours = soccerHours + volleyballHours;

    // Display the information entered by the user.
    cout << "\nMy Sports Summary\n";
    cout << "\n";

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

    cout << "\nKeep having fun and staying active!\n";

    // Save the sports summary to a text file.
    ofstream reportFile("report.txt");

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

    reportFile << "\nKeep having fun and staying active!\n";

    reportFile.close();

    return 0;
}