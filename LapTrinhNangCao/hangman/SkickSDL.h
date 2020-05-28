#ifndef SKICKSDL_H
#define SKICKSDL_H

#include <SDL.h>
#include <SDL_ttf.h>

#include <iostream>

#include "painter.h"
using namespace std;

class SkickSDL {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    Painter* painter;
    string title;
    int width;
    int height;

   public:
    SkickSDL(string title_, int width_, int height_);
    ~SkickSDL();
    void logSDLError(ostream& os, const string& msg, bool fatal);
    void openFont(string f, int size);
    void createTextTexture(string text, int x, int y);
    void createImageTexture(string fileName);
    void updateScreen();
};

#endif  // SKICKSDL_H
