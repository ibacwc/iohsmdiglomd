#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Window_s{
	SDL_Window* win;
	SDL_Renderer* rend;
}Window;

int create_window(Window* window, char* title, int w, int h);
void clear_window(Window* window);
void present_window(Window* window);
void destroy_window(Window* window);
SDL_Texture* load_image(Window* window, char* path);
void render_texture(Window* window, SDL_Texture* tex, int w, int h, int x,\
					int y, double angle);
#endif

