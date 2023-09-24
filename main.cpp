#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0));
    int bestScore = numeric_limits<int>::max(); // Initialize best score to a very high value
    char playAgain = 'y';

    cout << "Welcome to the Guessing Game!" << endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        int difficulty;
        cout << "Choose the difficulty level:" << endl;
        cout << "1. Easy (1-50)" << endl;
        cout << "2. Medium (1-100)" << endl;
        cout << "3. Hard (1-200)" << endl;
        cout << "Enter your choice (1/2/3): ";
        cin >> difficulty;

        int upperLimit;
        switch (difficulty) {
            case 1:
                upperLimit = 50;
                break;
            case 2:
                upperLimit = 100;
                break;
            case 3:
                upperLimit = 200;
                break;
            default:
                cout << "Invalid choice. Setting difficulty to Medium (1-100)." << endl;
                upperLimit = 100;
                break;
        }

        int secretNumber = rand() % upperLimit + 1;
        int attempts = 0;
        int guess;

        cout << "I'm thinking of a number between 1 and " << upperLimit << "." << endl;

        while (true) {
            try {
                cout << "Your guess: ";
                cin >> guess;
                attempts++;

                if (guess < secretNumber) {
                    cout << "Too low! Try again." << endl;
                } else if (guess > secretNumber) {
                    cout << "Too high! Try again." << endl;
                } else {
                    cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
                    if (attempts < bestScore) {
                        bestScore = attempts;
                        cout << "New best score!" << endl;
                    }
                    break;
                }
            } catch (const exception& e) {
                cout << "Invalid input. Please enter a number between 1 and " << upperLimit << "." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Best score: " << bestScore << " attempts" << endl;
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}
