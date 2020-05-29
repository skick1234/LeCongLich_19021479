#include "Game.h"
#include "SkickSDL.h"

using namespace std;

const int PLAY_TIME = 60;
const int SCREEN_WIDTH = 950;
const int SCREEN_HEIGHT = 900;
const string WINDOW_TITLE = "Hangman";

int main(int argc, char* argv[]) {
    SkickSDL* SDL = new SkickSDL(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL->openFont("VeraMoBd.ttf", 30);
    srand(time(0));
    Game* hangman = new Game(SDL, PLAY_TIME);
    while (hangman->playing) {
        hangman->startGame();
        do {
            hangman->guessEvent();     // handle SDL key press event
            hangman->renderGameSDL();  // render SDL game
            hangman->handleGuess();    // handle game based on event
            hangman->updateTime();     // update playtime
        } while (hangman->guessing());
        hangman->gameOver();  // handle gameover data and render SDL
    }
    return 0;
}
