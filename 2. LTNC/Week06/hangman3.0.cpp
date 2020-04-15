#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

#include "draw.h"
#include "utility.h"

using namespace std;

char readAGuess()
{
    char guess;
    cout << "Please enter your next guess: ";
    cin >> guess;
    return guess;
}

void update(string& guessedWord, const string& word, char guess)
{
    int n = guessedWord.length();
    for (int i = 0; i < n; i++) {
        if (word[i] == guess)
            guessedWord[i] = guess;
    }
}

int main(int argc, char* argv[])
{
    srand(time(0));
    string fileName = argc > 1 ? argv[1] : "ogden_picturable_200.txt";

    while (true) {
        string word = chooseWord(fileName);
        if (word.empty()) {
            cout << "No word available in " << fileName << endl;
            return 0;
        }
        string guessedWord = string(word.length(), '-');
        int badGuessCount = 0;
        const int MAX_BAD_GUESS = 7;
        string badGuess;

        do {
            renderGame(guessedWord, badGuessCount, badGuess);
            char guess = readAGuess();

            if (contains(word, guess)) {
                update(guessedWord, word, guess);
            } else {
                badGuessCount++;
                badGuess += guess;
            }
        } while (badGuessCount < MAX_BAD_GUESS && guessedWord != word);

        printGameOverInfo(guessedWord, word, badGuessCount);
        cout << "Do you want more (Y/N) ?";
        string answer;
        cin.ignore(1);
        getline(cin, answer);
        if (answer != "Y" && answer != "y")
            break;
    }

    return 0;
}
