#include <SDL.h>
#include <SDL_ttf.h>

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "DrawSDL.h"
#include "draw.h"
#include "painter.h"
#include "utility.h"

using namespace std;

const int PLAY_TIME = 90;

void update(string& guessedWord, const string& word, char guess) {
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

void renderGameSDL(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, string guessedWord, int badGuessCount, int suggested, int maxSuggest, int timeLeft, int win, int lose, string badGuess = "") {
    Painter painter = Painter(window, renderer, font);
    SDL_Texture* texture = NULL;
    texture = painter.loadTexture("hang" + to_string(badGuessCount) + ".png");
    painter.createImage(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);

    SDL_Rect srcRest;
    SDL_Rect desRect;
    SDL_Texture* textTexture = NULL;
    textTexture = painter.textTexture("Time: " + to_string(timeLeft), &srcRest, &desRect, 750, 5);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    textTexture = nullptr;
    textTexture = painter.textTexture("Win : " + to_string(win), &srcRest, &desRect, 750, 45);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    textTexture = nullptr;
    textTexture = painter.textTexture("Lose: " + to_string(lose), &srcRest, &desRect, 750, 85);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    textTexture = nullptr;
    textTexture = painter.textTexture("Current Guess    :     " + guessedWord, &srcRest, &desRect, 100, 750);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    textTexture = nullptr;
    textTexture = painter.textTexture("Bad Guesses      :     " + badGuess, &srcRest, &desRect, 100, 800);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    textTexture = nullptr;
    textTexture = painter.textTexture("Used suggestions :     " + to_string(suggested) + "/" + to_string(maxSuggest) + " (Press 'Space')", &srcRest, &desRect, 100, 850);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
}

void renderGameOverSDL(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, int i, string guessedWord, string word, int badGuessCount, int suggested, int maxSuggest, int win, int lose, bool timeup) {
    Painter painter = Painter(window, renderer, font);

    SDL_Texture* texture = NULL;
    string status = (guessedWord == word ? "free" : "hanged");
    texture = painter.loadTexture(status + to_string(i) + ".png");
    painter.createImage(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);

    SDL_Rect srcRest;
    SDL_Rect desRect;
    SDL_Texture* textTexture = NULL;
    textTexture = painter.textTexture("Win : " + to_string(win), &srcRest, &desRect, 750, 45);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    if (timeup) {
        textTexture = nullptr;
        textTexture = painter.textTexture("Time Up!!!", &srcRest, &desRect, 750, 5);
        SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
        SDL_DestroyTexture(textTexture);
    }

    textTexture = nullptr;
    textTexture = painter.textTexture("Lose: " + to_string(lose), &srcRest, &desRect, 750, 85);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    if (guessedWord == word) {
        textTexture = nullptr;
        textTexture = painter.textTexture("Congrats!!! You are free.", &srcRest, &desRect, 100, 750);
        SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
        SDL_DestroyTexture(textTexture);
    } else {
        textTexture = nullptr;
        textTexture = painter.textTexture("Game Over!!! You are hanged!", &srcRest, &desRect, 100, 750);
        SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
        SDL_DestroyTexture(textTexture);
    }

    textTexture = nullptr;
    textTexture = painter.textTexture("Correct word: " + word, &srcRest, &desRect, 100, 800);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);

    textTexture = nullptr;
    textTexture = painter.textTexture("Press Enter to keep playing, ESC to exit.", &srcRest, &desRect, 100, 850);
    SDL_RenderCopy(renderer, textTexture, &srcRest, &desRect);
    SDL_DestroyTexture(textTexture);


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    TTF_Font* font = NULL;
    font = TTF_OpenFont("VeraMoBd.ttf", 30);
    srand(time(0));
    string fileName = argc > 1 ? argv[1] : "words.txt";
    int win = 0, lose = 0;
    bool hangmanPlaying = true;
    while (hangmanPlaying) {
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
            char guess = '~';
            SDL_Event e;
            if (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT || (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)) {
                    hangmanPlaying = false;
                    break;
                } else if (e.type == SDL_KEYUP) {
                    if (e.key.keysym.sym == SDLK_SPACE)
                        guess = '$';
                    else
                        guess = tolower(SDL_GetKeyName(e.key.keysym.sym)[0]);
                }
            }
            renderGameSDL(window, renderer, font, guessedWord, badGuessCount, suggested, maxSuggest, (int)difftime(startTime + PLAY_TIME, now), win, lose, badGuess);
            // renderGame(guessedWord, badGuessCount, suggested, maxSuggest, startTime, badGuess); 19021479

            if (guess != '~') {
                if (guess == '$') {
                    getSuggest(guessedWord, word, suggested, maxSuggest);
                    continue;
                }

                if (contains(word, guess)) {
                    update(guessedWord, word, guess);
                    updateSuggest(guessedWord, word, suggested, maxSuggest);
                } else if (!contains(badGuess, guess)) {
                    badGuessCount++;
                    badGuess += guess;
                }
            }
            time(&now);
        } while (badGuessCount < MAX_BAD_GUESS && guessedWord != word && difftime(startTime + PLAY_TIME, now) > 0);
        if (guessedWord != word)
            lose++;
        else
            win++;
        int i = 0;
        time_t start;
        time(&start);
        while (hangmanPlaying) {
            SDL_Event e;
            if (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT || (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)) {
                    hangmanPlaying = false;
                    break;
                } else if (e.type == SDL_KEYUP &&
                           (e.key.keysym.sym == SDLK_RETURN ||
                            e.key.keysym.sym == SDLK_RETURN2 ||
                            e.key.keysym.sym == SDLK_KP_ENTER)) {
                    hangmanPlaying = true;
                    break;
                }
            }
            renderGameOverSDL(window, renderer, font, i, guessedWord, word, badGuessCount, suggested, maxSuggest, win, lose, difftime(startTime + PLAY_TIME, now) <= 0);
            time(&now);
            if (difftime(now, start) >= 0.25) {
                time(&start);
                i++;
            }
            if (i == 4) i = 0;
        }
        // printGameOverInfo(guessedWord, word, badGuessCount, suggested, maxSuggest, win, lose, difftime(startTime + PLAY_TIME, now) <= 0); From Skick with <3
    }
    quitSDL(window, renderer);
    return 0;
}
