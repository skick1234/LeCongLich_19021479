#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <ctime>

using namespace std;


string getHangPicture(int badGuessCount)
{
    string picture[] = {"",
"   ------------\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |          |\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",

};
    return picture[badGuessCount];
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif // _WIN32
}

void renderGame(string guessedWord, int badGuessCount, int suggested, int maxSuggest, time_t startTime, string badGuess = "")
{
    time_t now;
    time(&now);
    clearScreen();
    cout <<
        "Current guess = " << guessedWord << endl <<
        "You have made bad " << badGuessCount << " guess" << (badGuessCount != 1 ? "es" : "") <<
        (badGuess.empty() ? "" : ": ") << badGuess << endl <<
        "Used suggestions: " << suggested << "/" << maxSuggest <<
        " (type \'suggest\' for suggestion)\nTime left: " << difftime(startTime + 60, now) << " seconds" << endl <<
        getHangPicture(badGuessCount) << endl;
}

const vector<string> HANGED = {
"   ------------\n"
"   |         /\n"
"   |        O\n"
"   |       /|\\\n"
"   |       / \\\n"
"   |         \n"
"   |         \n"
"   |         \n"
"   |         \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |           \\\n"
"   |            O\n"
"   |           /|\\\n"
"   |           / \\\n"
"   |             \n"
"   |             \n"
"   |             \n"
"   |             \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        "
};

void printGameOverInfo(string guessedWord, string word, int badGuessCount, int suggested, int maxSuggest, int win, int lose, bool timeup)
{
    clearScreen();
    if (timeup) cout << "Time Up!!\n";
    if (guessedWord != word) {
        cout << "Game Over!!! You are hanged" << endl
                << "The correct word is " << word << endl
                << HANGED[1] << endl;
        cout << "Win: " << win << " - Lose: " << lose << endl;
    } else {
        cout << "Congrats!!! You are free.\nThe correct word is " << word << endl;
        cout << "Win: " << win << " - Lose: " << lose << endl;
    }
}
