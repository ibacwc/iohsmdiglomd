#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "util.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Entity_s{
	Vector2f pos, vel;
	SDL_Texture* tex;
	SDL_Rect *src, *dst;
	int collisions[4];
}Entity;


#endif
