#ifndef __DRAW_H__
#define __DRAW_H__

#include <string>
#include <ctime>

std::string getHangPicture(int badGuessCount);
void clearScreen();
void renderGame(std::string guessedWord, int badGuessCount, int suggested, int maxSuggest, time_t startTime, std::string badGuess = "");
void printGameOverInfo(std::string guessedWord, std::string word, int badGuessCount, int suggested, int maxSuggest, int win, int lose, bool timeup);

#endif // __DRAW_H__
