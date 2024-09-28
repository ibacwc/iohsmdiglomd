#include "inc/window.h"
#include "inc/util.h"

int create_window(Window* window, char* title, int w, int h){
	SDL_Window* win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,\
		SDL_WINDOWPOS_UNDEFINED, w, h, 0);
	if(win == NULL){
		printf("Error creating window: %s\n", SDL_GetError());
		return -1;
	}
	SDL_Renderer* r = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if(r == NULL){
		SDL_DestroyWindow(win);
		printf("Error creating renderer: %s\n", SDL_GetError());
		return -1;
	}
	window->win = win;
	window->rend = r;
	return 0;
}
void clear_window(Window* window){
	SDL_RenderClear(window->rend);
	SDL_SetRenderDrawColor(window->rend, YELLOW.r, YELLOW.g, YELLOW.b, 255);
}
void present_window(Window* window){
	SDL_RenderPresent(window->rend);
}
void destroy_window(Window* window){
	SDL_DestroyRenderer(window->rend);
	SDL_DestroyWindow(window->win);
}
SDL_Texture* load_image(Window* window, char* path){
	SDL_Texture* ret = SDL_CreateTextureFromSurface(window->rend, IMG_Load(path));
	if (ret == NULL){
		printf("Error loading img at %s! %s\n", path, SDL_GetError());
		return NULL;
	}
	return ret;
}
void render_texture(Window* window, SDL_Texture* tex, int w, int h, int x,\
					int y, double angle){
	SDL_Rect dst = {x,y,w,h};
	SDL_RenderCopyEx(window->rend, tex, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
}
