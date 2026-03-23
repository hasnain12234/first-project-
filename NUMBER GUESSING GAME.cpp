//Muhammad Hasnain
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to give smart hints
void giveHint(int guess, int number) {
    int diff = abs(guess - number);

    if (diff == 0) return;
    else if (diff <= 3)
        cout << "?? Very very close!\n";
    else if (diff <= 10)
        cout << "?? Close!\n";
    else if (diff <= 20)
        cout << "?? Not too far.\n";
    else
        cout << "?? Far away!\n";

    if (guess > number)
        cout << "?? Too HIGH!\n";
    else
        cout << "?? Too LOW!\n";
}

int main() {
    srand(time(0));
    char playAgain;

    cout << "?? ===== WELCOME TO THE ULTIMATE GUESSING GAME ===== ??\n";

    do {
        int difficulty, maxAttempts;

        // Difficulty selection
        cout << "\nSelect Difficulty:\n";
        cout << "1. Easy (10 attempts)\n";
        cout << "2. Medium (7 attempts)\n";
        cout << "3. Hard (5 attempts)\n";
        cout << "Enter choice: ";
        cin >> difficulty;

        if (difficulty == 1) maxAttempts = 10;
        else if (difficulty == 2) maxAttempts = 7;
        else maxAttempts = 5;

        int number = rand() % 100 + 1;
        int guess, attempts = 0;
        bool guessed = false;

        cout << "\n?? I have selected a number between 1 and 100!\n";
        cout << "You have " << maxAttempts << " lives ??\n";

        while (attempts < maxAttempts) {
            cout << "\nEnter your guess: ";
            cin >> guess;

            attempts++;

            if (guess == number) {
                cout << "\n?? CORRECT! You guessed it in " << attempts << " attempts!\n";

                // Score system
                int score = (maxAttempts - attempts + 1) * 10;
                cout << "?? Your Score: " << score << endl;

                guessed = true;
                break;
            } else {
                giveHint(guess, number);
                cout << "?? Lives left: " << (maxAttempts - attempts) << endl;
            }
        }

        if (!guessed) {
            cout << "\n?? Game Over! The correct number was: " << number << endl;
        }

        cout << "\n?? Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n?? Thanks for playing! You're awesome!\n";

    return 0;
}
