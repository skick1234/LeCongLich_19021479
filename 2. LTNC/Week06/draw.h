#ifndef __DRAW_H__
#define __DRAW_H__

#include <string>

std::string getHangPicture(int badGuessCount);
void clearScreen();
void renderGame(std::string guessedWord, int badGuessCount, std::string badGuess = "");
void printGameOverInfo(std::string guessedWord, std::string word, int badGuessCount);

#endif // __DRAW_H__
