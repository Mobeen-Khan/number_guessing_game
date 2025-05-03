#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <limits>  

using namespace std;

int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;
    const int MAX_ATTEMPTS = 10;
    
   
    int secretNumber = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    int guess;
    int attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I've selected a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
    cout << "Can you guess it in " << MAX_ATTEMPTS << " tries or less?\n\n";
    
    while (attempts < MAX_ATTEMPTS) {
        cout << "Enter your guess (" << MIN_NUMBER << "-" << MAX_NUMBER << "): ";
        
        while (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        
        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            cout << "Please enter a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
            continue;
        }
        
        attempts++;
        
        if (guess < secretNumber) {
            cout << "Too low! ";
        } else if (guess > secretNumber) {
            cout << "Too high! ";
        } else {
            cout << "\nCongratulations! You guessed the number " << secretNumber;
            cout << " in " << attempts << " attempt" << (attempts == 1 ? "" : "s") << "!\n";
            return 0;
        }
        
       
        cout << "Attempts left: " << (MAX_ATTEMPTS - attempts) << "\n\n";
    }
    
    cout << "\nGame over! You've used all " << MAX_ATTEMPTS << " attempts.\n";
    cout << "The secret number was: " << secretNumber << "\n";
    
    return 0;
}