#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

string chooseWord()
{
    string vocabulary[] = {"angle", "ant", "apple", "arch", "arm", "army", "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy", "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button", "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest", "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord", "cow", "cup", "curtain", "cushion", "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye", "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly", "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun", "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse", "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot", "leaf", "leg", "library", "line", "lip", "lock", "map", "match", "monkey", "moon", "mouth", "muscle", "nail", "neck", "needle", "nerve", "net", "nose", "nut", "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin", "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump", "rail", "rat", "receipt", "ring", "rod", "roof", "root", "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt", "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring", "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach", "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella", "wall", "watch", "wheel", "whip", "whistle", "window", "wing", "wire", "worm" };

    cout << "vocabulary size = " << sizeof(vocabulary)/sizeof(string) << endl;
    return vocabulary[rand()%(sizeof(vocabulary)/sizeof(string))];
}

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

void renderGame(string guessedWord, string guessedChar, int badGuessCount)
{
    system("CLS");
    cout << "Word: " << guessedWord << endl <<
            "Guessed characters: " << guessedChar << endl <<
            "You have made bad " << badGuessCount << " guess(es)" << endl <<
            getHangPicture(badGuessCount) << endl;
}

char readAGuess()
{
    char guess;
    cout << "Please enter your next guess: ";
    cin >> guess;
    return tolower(guess);
}

bool contains(string word, char guess)
{
    return (word.find(guess) != string::npos);
}

string update(string guessedWord, string word, char guess)
{
    int n = guessedWord.length();
    for (int i = 0; i < n; i++) {
        if (word[i] == guess)
            guessedWord[i] = guess;
    }
    return guessedWord;
}

void printGameOverInfo(string guessedWord, string word, string guessedChar, int badGuessCount)
{
    renderGame(guessedWord, guessedChar, badGuessCount);
    if (guessedWord != word) {
        cout << "Game Over!!! You are hanged. Correct Word: " << word << endl;
    } else {
        cout << "Congrats!!! You are free" << endl;
    }
}

int main()
{
    srand(time(0));
    string word = chooseWord();
    string guessedWord = string(word.length(), '-');
    string guessedChar = "";
    int badGuessCount = 0;
    const int MAX_BAD_GUESS = 7;
    
    do {
        renderGame(guessedWord, guessedChar, badGuessCount);
        char guess = readAGuess();

        if (contains(word, guess)) {
            guessedWord = update(guessedWord, word, guess);
        } else if (!contains(guessedChar, guess)) {
            badGuessCount++;
            if (badGuessCount != 1) guessedChar += ", ";
            guessedChar += guess;
        }
    } while (badGuessCount < MAX_BAD_GUESS && guessedWord != word);
    printGameOverInfo(guessedWord, word, guessedChar, badGuessCount);
    cin;
    return 0;
}
