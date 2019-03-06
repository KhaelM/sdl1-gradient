#include <SDL/SDL.h>
#include "function.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 256

int main(int argc, char const *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1) {
        fprintf(stderr, "Error while initialising SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Gradient", NULL);


    SDL_Surface *screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, Rich, SDL_HWSURFACE); 
    
    if(screen == NULL) {
        fprintf(stderr, "Error while setting Video Mode: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);   
    }

    int posX = 0;
    int posY = 0;
    SDL_Rect position = {posX, posY};    
    SDL_Surface *lines[256] = {NULL};
    int gradient = 0;
    Uint32 color = 0;

    for(gradient = 0; gradient < WINDOW_HEIGHT; gradient++)
    {
        lines[gradient] = SDL_CreateRGBSurface(SDL_HWSURFACE, WINDOW_WIDTH, 1, Rich, 0, 0, 0, 0);
        color = SDL_MapRGB(screen->format, gradient, gradient, gradient);
        SDL_FillRect(lines[gradient], NULL, color);
        SDL_BlitSurface(lines[gradient], NULL, screen, &position);
        position.y++;
    }

    SDL_Flip(screen);
    
    pause();
    
    for(gradient = 0; gradient < WINDOW_HEIGHT; gradient++)
    {
        SDL_FreeSurface(lines[gradient]);
    }
    
    SDL_Quit();

    return EXIT_SUCCESS;
}
