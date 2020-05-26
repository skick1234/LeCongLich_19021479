#ifndef DRAWSDL_H_INCLUDED
#define DRAWSDL_H_INCLUDED

#include <SDL.h>
void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

#endif // DRAWSDL_H_INCLUDED
