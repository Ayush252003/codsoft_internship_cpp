#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    
    srand(time(0));

    int lowerBound = 1;
    int upperBound = 100;
    int numberToGuess = rand() % (upperBound - lowerBound + 1) + lowerBound;
    int numberOfAttempts = 0;
    int guessedNumber;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a random number between " << lowerBound << " and " << upperBound << "." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guessedNumber;
        numberOfAttempts++;

        if (guessedNumber < lowerBound || guessedNumber > upperBound) {
            cout << "Please enter a number between " << lowerBound << " and " << upperBound << "." << endl;
        } else if (guessedNumber < numberToGuess) {
            cout << "Try a higher number." << endl;
        } else if (guessedNumber > numberToGuess) {
            cout << "Try a lower number." << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << numberToGuess << " in " << numberOfAttempts << " attempts." << endl;
        }
    } while (guessedNumber != numberToGuess);

    cout << "Thanks for playing!" << endl;

    return 0;
}
