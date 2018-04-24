#include "rectangles.h"

int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);
	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		/* Draw stuff here */
		draw_stuff(instance);
		SDL_RenderPresent(instance.renderer);
	}
	return (0);
}

int init_instance(SDL_Instance *instance)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	/* Create new Window instance */
	instance->window = SDL_CreateWindow("SDL \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	/* Create new Renderer instance */
	instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}

void draw_stuff(SDL_Instance instance)
{
	int i, j, index;
	SDL_Rect r;
	SDL_Rect rects[64];
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
	SDL_SetRenderDrawColor(instance.renderer, 255, 0, 0, 255);
	SDL_RenderClear(instance.renderer);

index = 0;
for(i = 0; i < 8; i++)
{ 
for(j = 0; j < 8; j++)
{
rects[index].x = 50*(i + 1);
rects[index].y = 50*(j + 1);
rects[index].w = 50;
rects[index].h = 50;
index++;
}
}

	SDL_SetRenderDrawColor(instance.renderer, 0, 0xFF, 0, 0xFF);

// Render our SDL_Rect
// The top left pos of the rect will be at 50, 50
// It will stretch 50 to the left and 50 towards the bottom
SDL_RenderDrawRects( instance.renderer, rects, i*j );
 
// Render the changes above 
// ( which up until now had just happened behind the scenes )
SDL_RenderPresent( instance.renderer);
}
