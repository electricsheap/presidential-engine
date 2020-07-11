
#include <SDL2/SDL.h>

#include "pres.h"
#include "pres_internal.h"

PRES_Window* pres_main_window;
PRES_Renderer* pres_main_renderer;

PRES_Color pres_clear_color = { .r = 100, .g = 100, .b = 100, .a = 255 };

// create the main window and set up SDL
int PRES_RendererInit( const char* title , Uint32 width, Uint32 height )
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		LOG_SDL_ERROR("SDL not initialized\n");
		return -1;
	}
	printf("sdl initilized!\n");

	pres_main_window = SDL_CreateWindow( title, 0, 0, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI );
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

void PRES_SetClearColor( PRES_Color new_color );
void PRES_SetDrawColor( PRES_Color new_color );

// clears the window with clear color
void PRES_RenderClear()
{
	PRES_SetDrawColor( pres_clear_color );
	SDL_RenderClear( pres_main_renderer );
}

// renders a full scene
void PRES_RenderScene()
{
	
	PRES_SetClearColor( (PRES_Color){ 255, 255, 255, 255 } );
	PRES_RenderClear();
	PRES_SetDrawColor( (SDL_Color){ 100, 100, 100, 100 } );
	
	SDL_RenderFillRect( pres_main_renderer, &(SDL_Rect){ 10, 10, 100, 100 } );
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
