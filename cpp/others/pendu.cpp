#include <iostream>

using namespace std;

int main () {
    int lives = 8; // number of lives 
    string words[] = {"apple", "sanctuary", "revolution", "fighting", "opressor", "liberty", "violence"};
    int rdIndex = rand()%6;
    string secretWord = words[rdIndex]; // make sur all lowercase
    int wordlen = secretWord.length(); // length of secret word
    char guessed; // guessed character
    char foundLetters[wordlen];
    for (int i=0; i<wordlen; i++) { // setting up empty list
        foundLetters[i] = '_';
    }
    cout << "Word length : " << wordlen << endl;
    while (lives > 0) {
        // cout << "Word length is : " << wordlen << endl;
        cout << "Enter the character (lowercase) : ";
        cin >> guessed;
        if (secretWord.find(guessed) == string::npos) { // if char not in string
            cout << "The letter " << guessed << " was not in the word" << endl;
            lives--; // decrement lives 
            if (lives == 0) {
                cout << "Game Over ! " << endl;
                break;
            }
            else {
                cout << lives << " live(s) left" << endl;
            }
        }
        else { // if char in word
            for (int i=0; i<wordlen; i++) {
                if (secretWord[i] == guessed) {
                    foundLetters[i] = guessed;
                }
            }
        }
        string testIfWord = ""; // test if word is correct
        for (int i=0; i<wordlen; i++) {
            testIfWord += foundLetters[i];
        }
        if (testIfWord == secretWord) {
            cout << "You won !" << endl;
            break;
        }
        cout << "Current found : " << testIfWord << endl;
    }
    return 0;
}
