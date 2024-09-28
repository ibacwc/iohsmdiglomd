#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

extern SDL_Color  BLACK;
extern SDL_Color  WHITE;
extern SDL_Color    RED;
extern SDL_Color  GREEN; 
extern SDL_Color   BLUE;
extern SDL_Color YELLOW;


enum INIT_FLAGS {SDL_BASE = 0, SDL_IMAGE = 1, SDL_MIXER = 2, SDL_TTF = 4,\
				 SDL_EVERYTHING = 9999};

int init_sdl(int FLAGS);

#endif
