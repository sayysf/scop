// sudo apt install vulkan-tools
// sudo apt install libvulkan-dev
// sudo apt install vulkan-validationlayers-dev spirv-tools
// sudo apt install libglm-dev

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_vulkan.h>
#include <SDL2/SDL_render.h>

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>


#include <stdio.h>
#include <stdbool.h>

 

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main( int argc, char* args[] )
{


	//The window we'll be rendering to
	SDL_Window* window = NULL;
	SDL_Renderer *rr;
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	SDL_Surface *png;
	SDL_Surface *dot;
	SDL_RWops *rpng;
	SDL_Rect rec = {0};
	SDL_Rect rec2 = {0};
 (void)rec2;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    //Create window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
        return (1);
    rr = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (rr == NULL)
        return (1);
    SDL_SetRenderDrawColor(rr, 0xFF, 0xFF, 0xFF, 0xFF );
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    
    SDL_Surface* loadedSurface = IMG_Load("./42microchip.png");
    if (!loadedSurface)
        return (2);
    SDL_Texture *newTexture = SDL_CreateTextureFromSurface( rr, loadedSurface );
    SDL_FreeSurface( loadedSurface );

    
    
    SDL_Event e; bool quit = false;
    while( quit == false)
    {
        while( SDL_PollEvent( &e ) )
        {
                if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                    quit = false;
                                //Clear screen
               // SDL_RenderClear( rr );

                //Render texture to screen
                SDL_RenderCopy( rr, newTexture, NULL, NULL );

                //Update screen
                SDL_RenderPresent( rr );
            if (e.motion.state == true)
            {
            }
        }
        
    }
    return (0);
}
