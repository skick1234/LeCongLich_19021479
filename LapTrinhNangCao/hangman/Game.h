#ifndef GAME_H
#define GAME_H
#include <ctime>
#include <string>

#include "SkickSDL.h"
using namespace std;

class Game {
    const int MAX_BAD_GUESS = 7;
    const string WORDS = "words.txt";
    SkickSDL* SDL;
    int playTime;
    int win;
    int lose;
    bool quit;
    string word;
    char guessChar;
    string guessedWord;
    int badGuessCount;
    int suggested;
    int maxSuggest;
    int timeLeft;
    string badGuess;
    time_t startTime;

   public:
    bool playing;
    Game(SkickSDL* SkickSDL, int time);
    void getSuggest();
    void updateGuessedWord();
    void updateSuggest();
    bool guessing();
    void guessEvent();
    void handleGuess();
    void updateTime();
    void initWord();
    void startGame();
    void badGuessed();
    void gameOver();
    void checkContinue(SDL_Event e);
    void renderGameSDL();
    void renderGameOverSDL(int imageIndex);
    void createGameOverSDL();
};

#endif  // GAME_H
