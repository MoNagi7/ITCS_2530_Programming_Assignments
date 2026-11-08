
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    double soccerHours;
    int volleyballHours;
    int daysPlayed;
    double totalHours;
    string playerName;
    int menuChoice;

    // Ask the user questions about sports.
    cout << "Welcome to My Sports Program!\n\n";

    cout << "What is your full name? ";
    getline(cin, playerName);

    cout << "How many hours do you play soccer each week? ";
    cin >> soccerHours;

    // Check if the soccer hours are valid.
    if (cin.fail() || soccerHours < 0)
    {
        cout << "Invalid soccer hours. Please enter a non-negative number.\n";
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


    // Repeat the menu until the user chooses Exit.
    do
    {


        // Display the sports menu.
        cout << "\nSports Menu\n";
        cout << "1. View Sports Summary\n";
        cout << "2. Compare Soccer and Volleyball Hours\n";
        cout << "3. Check Weekly Activity Level\n";
        cout << "4. Exit\n";


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
            break;

        case 2:
            cout << "\nYou selected Compare Sports Hours.\n";

            // Compare soccer and volleyball hours.
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
            cout << "\nYou selected Check Weekly Activity Level.\n";

            // Check the weekly sports activity.
            if (daysPlayed >= 3 && totalHours >= 5)
            {
                cout << "You met your weekly sports activity goal.\n";
            }
            else
            {
                cout << "You did not meet your weekly sports activity goal.\n";
            }
            break;


        case 4:
            cout << "\nThank you for using My Sports Program!\n";
            break;

        }

        // Show the summary if the user selects option 1.
        if (menuChoice == 1)
        {
            // Display the information entered by the user.
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

            cout << "\nKeep having fun and staying active!\n";

            // Show the total sports hours for three weeks.
            cout << "\nThree-Week Sports Hours Projection\n";

            for (int week = 1; week <= 3; week++)
            {
                cout << "Total hours after week " << week
                    << ": " << totalHours * week << "\n";
            }
        }

        // Repeat the sports menu until Exit is selected.
    } while (menuChoice != 4);

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