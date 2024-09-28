#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "inc/window.h"
#include "inc/util.h"
#define FPS 60
#define DELAY 1000/FPS

Window window;
int RUN = 0;
double dT = 0.0;
SDL_Texture* err_tex;

int init(){
	if (init_sdl(SDL_EVERYTHING)){
		printf("Error in init\n");
		return 0;
	}
	if (create_window(&window, "CBSP", 800, 600))
		return 0;

	err_tex = load_image(&window, "chuddie.jpg");
	return 1;
}
void handle_keydown(SDL_Keycode key){
	if ( key == SDLK_ESCAPE)
		RUN = 0;
}
void input(){
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT)
			RUN = 0;
		if (e.type == SDL_KEYDOWN)
			handle_keydown(e.key.keysym.sym);

	}
}
void render(){
	clear_window(&window);
	render_texture(&window, err_tex, 128, 128, 400, 300, 0.0);
	present_window(&window);
}
void update(){

}
int main(int argc, char** argv){
	RUN = init();
	while(RUN){
		Uint32 start = SDL_GetTicks();
		input();
		update();
		render();
		Uint32 end = SDL_GetTicks();
		dT = (double)(end - start)/1000;
		if (end-start < DELAY){
			SDL_Delay((DELAY - (end-start)));
		}
	}
	return 0;
}
