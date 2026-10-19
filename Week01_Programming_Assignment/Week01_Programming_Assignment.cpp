
#include <iostream>
using namespace std;

int main()
{
    int soccerHours;
    int volleyballHours;
    int daysPlayed;
    int totalHours;

    // Ask the user three questions about sports.
    cout << "Welcome to My Sports Program!\n\n";

    cout << "How many hours do you play soccer each week? ";
    cin >> soccerHours;

    cout << "How many hours do you play volleyball each week? ";
    cin >> volleyballHours;

    cout << "How many days do you play sports each week? ";
    cin >> daysPlayed;

    // Calculate the total hours spent playing sports.
    totalHours = soccerHours + volleyballHours;

    // Display the information entered by the user.
    cout << "\nMy Sports Summary\n";
    cout << "You play soccer for " << soccerHours;
    cout << " hours and volleyball for " << volleyballHours;
    cout << " hours each week. You play sports ";
    cout << daysPlayed << " days a week. ";
    cout << "You spend a total of " << totalHours;
    cout << " hours playing sports each week. ";
    cout << "Keep having fun and staying active!\n";

    return 0;
}
