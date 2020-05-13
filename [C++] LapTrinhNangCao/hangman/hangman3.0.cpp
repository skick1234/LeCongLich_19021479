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
    string guess;
    cout << "Please enter your next guess: ";
    cin >> guess;
    if (guess == "suggest") return '$';
    return tolower(guess[0]);
}

void update(string& guessedWord, const string& word, char guess)
{
    int n = guessedWord.length();
    for (int i = 0; i < n; i++) {
        if (word[i] == guess)
            guessedWord[i] = guess;
    }
}

void updateSuggest(string& guessedWord, const string& word, int& suggested, int& maxSuggest) {
    if (suggested < maxSuggest) {
        int c = 0, n = guessedWord.length();
        for (int i = 0; i < n; i++)
            if (guessedWord[i] == '-')
                c++;
        maxSuggest = c / 2;
    }
}

void getSuggest(string& guessedWord, const string& word, int& suggested, int& maxSuggest) {
    if (suggested < maxSuggest) {
        suggested++;
        int n = guessedWord.length();
        for (int i = 0; i < n; i++) {
            if (guessedWord[i] == '-') {
                guessedWord[i] = word[i];
                break;
            }
        }
    }
    updateSuggest(guessedWord, word, suggested, maxSuggest);
}

int main(int argc, char* argv[])
{
    srand(time(0));
    string fileName = argc > 1 ? argv[1] : "ogden_picturable_200.txt";
    int win = 0, lose = 0;

    while (true) {
        string word = chooseWord(fileName);
        if (word.empty()) {
            cout << "No word available in " << fileName << endl;
            system("pause");
            return 0;
        }
        string guessedWord = string(word.length(), '-');
        int badGuessCount = 0;
        const int MAX_BAD_GUESS = 7;
        string badGuess;
        int suggested = 0;
        int maxSuggest = word.length() / 2;
        time_t startTime, now;
        time(&startTime);

        do {
            renderGame(guessedWord, badGuessCount, suggested, maxSuggest, startTime, badGuess);
            char guess = readAGuess();

            if (guess == '$') {
                getSuggest(guessedWord, word, suggested, maxSuggest);
                continue;
            }

            if (contains(word, guess)) {
                update(guessedWord, word, guess);
                updateSuggest(guessedWord, word,suggested, maxSuggest);
            } else if (!contains(badGuess, guess)) {
                badGuessCount++;
                badGuess += guess;
            }
            time(&now);
        } while (badGuessCount < MAX_BAD_GUESS && guessedWord != word && difftime(startTime + 60, now) > 0);

        if (guessedWord != word) lose++;
        else win++;

        printGameOverInfo(guessedWord, word, badGuessCount, suggested, maxSuggest, win, lose, difftime(startTime + 60, now) <= 0);
        cout << "Do you want more (Y/N) ? ";
        string answer;
        cin.ignore(1);
        getline(cin, answer);
        if (answer != "Y" && answer != "y")
            break;
    }

    return 0;
}
