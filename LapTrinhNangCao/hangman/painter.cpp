#include "painter.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

Painter::Painter(SDL_Window* window = nullptr, SDL_Renderer* renderer_ = nullptr, TTF_Font* font_ = nullptr) : renderer(renderer_), font(font_) {
    if (window = nullptr) return;
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0)
        SDL_GetWindowSize(window, &width, &height);

    setPosition(width / 2, height / 2);
    setAngle(0);
    setColor(WHITE_COLOR);
    clearWithBgColor(BLUE_COLOR);
}

void Painter::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

void Painter::setAngle(float angle) {
    this->angle = angle - floor(angle / 360) * 360;
}

void Painter::setColor(SDL_Color color) {
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}

void Painter::clearWithBgColor(SDL_Color bgColor) {
    SDL_Color curColor = color;
    setColor(bgColor);
    SDL_RenderClear(renderer);
    setColor(curColor);
}

void Painter::moveForward(float length) {
    float prevX = x, prevY = y;
    jumpForward(length);
    SDL_RenderDrawLine(renderer, (int)prevX, (int)prevY, (int)x, (int)y);
}

void Painter::jumpForward(float length) {
    float rad = (angle / 180) * M_PI;
    x += (cos(rad) * length);
    y -= (sin(rad) * length);
}

void Painter::setRandomColor() {
    Uint8 r = rand() % 256;
    Uint8 g = rand() % 256;
    Uint8 b = rand() % 256;
    SDL_Color color = {r, g, b};
    setColor(color);
}

void Painter::createCircle(float radius) {
    double rad = (angle / 180) * M_PI;
    int centerX = x + cos(rad) * radius;
    int centerY = y - sin(rad) * radius;

    int dx = radius;
    int dy = 0;
    int err = 0;

    while (dx >= dy) {
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY - dy);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY - dy);

        if (err <= 0) {
            dy += 1;
            err += 2 * dy + 1;
        }
        if (err > 0) {
            dx -= 1;
            err -= 2 * dx + 1;
        }
    }
}

void Painter::createSquare(float size) {
    for (int i = 0; i < 4; ++i) {
        moveForward(size);
        turnLeft(90);
    }
}

void Painter::createParallelogram(float size) {
    for (int i = 0; i < 2; ++i) {
        moveForward(size);
        turnLeft(60);
        moveForward(size);
        turnLeft(120);
    }
}

SDL_Texture* Painter::loadTexture(string path) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
        cout << "Unable to load image " << path << " SDL_image Error: " << IMG_GetError() << endl;
    else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
            cout << "Unable to create texture from " << path << " SDL Error: " << SDL_GetError() << endl;
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

SDL_Texture* Painter::textTexture(string text, SDL_Rect* srcRest, SDL_Rect* desRect, float _x, float _y) {
    SDL_Color fg = {0, 0, 0};
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), fg);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    TTF_SizeText(font, text.c_str(), &srcRest->w, &srcRest->h);
    srcRest->x = 0;
    srcRest->y = 0;
    desRect->x = _x;
    desRect->y = _y;
    desRect->w = srcRest->w;
    desRect->h = srcRest->h;
    return texture;
}

bool Painter::createImage(SDL_Texture* texture) {
    if (texture == NULL) return false;
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    return true;
}
