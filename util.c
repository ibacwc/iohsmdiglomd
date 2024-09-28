#include "inc/util.h"

SDL_Color BLACK   = 		  {0,0,0};
SDL_Color WHITE   =   {255, 255, 255};
SDL_Color RED 	  = 	  {255, 0, 0};
SDL_Color GREEN   = 	  {0, 255, 0};
SDL_Color BLUE    =       {0, 0, 255};
SDL_Color YELLOW  = 	{255, 255, 0};

int init_sdl(int FLAGS){
	switch (FLAGS){
		case 2:
			if (SDL_Init(SDL_INIT_EVERYTHING)){
				printf("SDL failed on init: %s\n", SDL_GetError());
				return -1;
			}
			if (!Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG )){
				printf("MIX failed on init: %s\n", Mix_GetError());
				return -1;
			}
			break;
		case 4:
			if (SDL_Init(SDL_INIT_EVERYTHING)){
				printf("SDL failed on init: %s\n", SDL_GetError());
				return -1;
			}
			if (TTF_Init()){
				printf("TTF failed on init: %s\n", TTF_GetError());
				return -1;
			}
			break;
		case 5:
			if (SDL_Init(SDL_INIT_EVERYTHING)){
				printf("SDL failed on init: %s\n", SDL_GetError());
				return -1;
			}
			if (TTF_Init()){
				printf("TTF failed on init: %s\n", TTF_GetError());
				return -1;
			}
			if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)){
				printf("IMG failed on init: %s\n", IMG_GetError());
				return -1;
			}
			break;
		case 6:
			if (SDL_Init(SDL_INIT_EVERYTHING)){
				printf("SDL failed on init: %s\n", SDL_GetError());
				return -1;
			}
			if (TTF_Init()){
				printf("TTF failed on init: %s\n", TTF_GetError());
				return -1;
			}
			if (!Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG )){
				printf("MIX failed on init: %s\n", Mix_GetError());
				return -1;
			}
			break;
		default:
		case 3:
			if (!Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG )){
				printf("MIX failed on init: %s\n", Mix_GetError());
				return -1;
			}
		case 1:
			if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)){
				printf("IMG failed on init: %s\n", IMG_GetError());
				return -1;
			}
		case 0:
			if (SDL_Init(SDL_INIT_EVERYTHING)){
				printf("SDL failed on init: %s\n", SDL_GetError());
				return -1;
			}
			break;
	}
	return 0;
}

int coll_rect(SDL_Rect r1, SDL_Rect r2);
int coll_num(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
