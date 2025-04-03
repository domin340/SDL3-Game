#include <SDL3/SDL.h>
#include <stdio.h>

int main()
{
    // initialize sdl
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("Could not initialize sdl3: %s\n", SDL_GetError());
    }

    return 0;
}
