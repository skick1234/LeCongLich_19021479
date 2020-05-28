#include "Game.h"

#include <ctime>

#include "SkickSDL.h"
#include "utility.h"

Game::Game(SkickSDL* SkickSDL, int time) : SDL(SkickSDL), playTime(time) {
    playing = true;
    win = 0;
    lose = 0;
}

void Game::startGame() {
    quit = false;
    system("cls");
    initWord();
    guessedWord = string(word.length(), '-');
    badGuessCount = 0;
    badGuess = "";
    suggested = 0;
    maxSuggest = word.length() / 2;
    time(&startTime);
}

void Game::initWord() {
    word = chooseWord(WORDS);
    if (word.empty()) {
        cout << "No word available in " << WORDS << endl;
        system("pause");
        playing = false;
        quit = true;
    }
}

void Game::guessEvent() {
    SDL_Event event;
    guessChar = '~';
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            playing = false;
            quit = true;
        } else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) {
            playing = false;
        } else if (event.type == SDL_KEYUP) {
            string keyName = SDL_GetKeyName(event.key.keysym.sym);
            if (event.key.keysym.sym == SDLK_SPACE)
                guessChar = '$';
            else if (keyName.length() == 1 && keyName[0] >= 'A' && keyName[0] <= 'Z')
                guessChar = tolower(keyName[0]);
        }
    }
}

void Game::handleGuess() {
    if (guessChar == '~') return;
    if (guessChar == '$')
        getSuggest();
    else if (contains(word, guessChar))
        updateGuessedWord();
    else if (!contains(badGuess, guessChar))
        badGuessed();
}

void Game::badGuessed() {
    badGuessCount++;
    badGuess += guessChar;
}

bool Game::guessing() {
    return badGuessCount < MAX_BAD_GUESS && guessedWord != word && timeLeft > 0 && playing;
}

void Game::updateTime() {
    time_t now;
    time(&now);
    timeLeft = playTime - difftime(now, startTime);
}

void Game::gameOver() {
    if (guessedWord != word)
        lose++;
    else
        win++;
    createGameOverSDL();
}

void Game::updateGuessedWord() {
    int n = guessedWord.length();
    for (int i = 0; i < n; i++) {
        if (word[i] == guessChar)
            guessedWord[i] = guessChar;
    }
    updateSuggest();
}

void Game::updateSuggest() {
    if (suggested < maxSuggest) {
        int suggest = 0, n = guessedWord.length();
        for (int i = 0; i < n; i++)
            if (guessedWord[i] == '-')
                suggest++;
        maxSuggest = suggest / 2 + suggested;
    }
}

void Game::getSuggest() {
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
}

void Game::renderGameSDL() {
    SDL->createImageTexture("hang" + to_string(badGuessCount) + ".png");
    SDL->createTextTexture("Time: " + to_string(timeLeft), 750, 5);
    SDL->createTextTexture("Win : " + to_string(win), 750, 45);
    SDL->createTextTexture("Lose: " + to_string(lose), 750, 85);
    SDL->createTextTexture("Current Guess    :     " + guessedWord, 100, 750);
    SDL->createTextTexture("Bad Guesses      :     " + badGuess, 100, 800);
    SDL->createTextTexture("Used suggestions :     " + to_string(suggested) + "/" + to_string(maxSuggest) + "   (Press 'Space')", 100, 850);
    SDL->updateScreen();
}

void Game::renderGameOverSDL(int imageIndex) {
    string status = (guessedWord == word ? "free" : "hanged");
    SDL->createImageTexture(status + to_string(imageIndex) + ".png");
    if (timeLeft <= 0)
        SDL->createTextTexture("Time Up!!!", 750, 5);
    SDL->createTextTexture("Win : " + to_string(win), 750, 45);
    SDL->createTextTexture("Lose: " + to_string(lose), 750, 85);
    if (guessedWord == word)
        SDL->createTextTexture("Congrats!!! You are free.", 100, 750);
    else
        SDL->createTextTexture("Game Over!!! You are hanged!", 100, 750);
    SDL->createTextTexture("Correct word: " + word, 100, 800);
    SDL->createTextTexture("Press Enter to keep playing, ESC to exit.", 100, 850);
    SDL->updateScreen();
}

void Game::createGameOverSDL() {
    int imageIndex = 0;
    time_t start, now;
    time(&start);
    while (!quit) {
        SDL_Event e;
        checkContinue(e);
        renderGameOverSDL(imageIndex);
        // framerate
        time(&now);
        if (difftime(now, start) >= 0.25) {
            time(&start);
            imageIndex++;
            if (imageIndex == 4) imageIndex = 0;
        }
    }
}

void Game::checkContinue(SDL_Event e) {
    if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT || (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)) {
            playing = false;
            quit = true;
        } else if (e.type == SDL_KEYUP &&
                   (e.key.keysym.sym == SDLK_RETURN ||
                    e.key.keysym.sym == SDLK_RETURN2 ||
                    e.key.keysym.sym == SDLK_KP_ENTER)) {
            playing = true;
            quit = true;
        }
    }
}
