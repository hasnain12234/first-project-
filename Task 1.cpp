//Muhammad Hasnain
#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    char choice;

    // Seed the random number generator
    srand(time(0));

    do {
        // Generate two random numbers between 1 and 6
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;

        // Display results
        cout << "You rolled: " << dice1 << " and " << dice2 << endl;

        // Ask user to roll again
        cout << "Do you want to roll again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
