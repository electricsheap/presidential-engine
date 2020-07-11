
#include <SDL2/SDL.h>

#include "pres.h"
#include "pres_internal.h"

PRES_Window* pres_main_window;
static PRES_Renderer* pres_main_renderer;

static PRES_Color clear_color = { .r = 100, .g = 100, .b = 100, .a = 255 };

// create the main window and set up SDL
int PRES_RendererInit( const char* title , Uint32 width, Uint32 height )
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		LOG_SDL_ERROR("SDL not initialized\n");
		return -1;
	}
	printf("sdl initilized!\n");

	pres_main_window = SDL_CreateWindow( title, 0, 0, width, height, SDL_WINDOW_SHOWN );
	if( NULL == pres_main_window ) {
		LOG_SDL_ERROR("SDL Window not created\n");
		SDL_Quit();
		return -1;
	}
	printf("sdl window created!!\n");

	pres_main_renderer = SDL_CreateRenderer( pres_main_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if( NULL == pres_main_renderer) {
		LOG_SDL_ERROR("SDL Renderer not created\n");
		SDL_DestroyWindow( pres_main_window );
		SDL_Quit();
		return -1;
	}
	printf("sdl renderer created!!!\n");

	

	return 0;
}

void PRES_SetRenderClear( PRES_Color new_color )
{
	clear_color = new_color;
}

// clears the window with clear color
void PRES_RenderClear()
{
	SDL_SetRenderDrawColor( pres_main_renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a );
	SDL_RenderClear( pres_main_renderer );
}

// renders a full scene
void PRES_RenderScene()
{
	SDL_Rect size = { 10, 10, 100, 100 };

	PRES_RenderClear();
	SDL_RenderDrawRect( pres_main_renderer, &size );
	SDL_RenderPresent( pres_main_renderer );
}

// close the main window and clean all rendering stuff
void PRES_RendererQuit()
{
	SDL_DestroyWindow( pres_main_window );
	pres_main_window = NULL;

	SDL_DestroyRenderer( pres_main_renderer );
	pres_main_renderer = NULL;

	SDL_Quit();
}
