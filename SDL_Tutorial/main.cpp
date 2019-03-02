#include <iostream>
#include <string>
#include <SDL.h>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

int maxX = 640;
int maxY = 480;

int main(int argc, char **argv) {
	/*if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
		return 1;
	}*/

	SDL_Window* win = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, maxX, maxY, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_Rect r;
	r.x = 150;
	r.y = 150;
	r.w = 150;
	r.h = 50;

	int changerX = 1;
	int changerY = 3;

	while (true)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		//CLEANS THE RENDERED STUFF THAT WAS THERE BEFORE IN HE COLOR SET UP
		SDL_RenderClear(renderer);

		//MOVE THE SQUARE POSITION
		if (r.x > maxX)
		{
			changerX = -1;
		}

		if (r.x < 0)
		{
			changerX = 1;
		}

		r.x += changerX;

		if (r.y > maxY)
		{
			changerY = -3;
		}

		if (r.y < 0)
		{
			changerY = 3;
		}

		r.y += changerY;

		//CHANGE THE COLOR OF THE RENDERER
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		//RENDER THE SQUARE WITH NEW POSITION AND NEW COLOR
		SDL_RenderFillRect(renderer, &r);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	

	SDL_Delay(1000);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}

void ChangeX(SDL_Rect &r, int &changer)
{

}

void ChangeY(SDL_Rect &r, int &changer)
{

}