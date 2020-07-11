
#include <SDL2/SDL.h>

#include "pres.h"
#include "pres_internal.h"

Pres_Window* pres_main_window;
Pres_Renderer* pres_main_renderer;
Pres_Color pres_clear_color = { .r = 100, .g = 100, .b = 100, .a = 255 };

// create the main window and set up SDL
int Pres_RendererInit( const char* title , Uint32 width, Uint32 height )
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

void Pres_SetClearColor( Pres_Color new_color );
void Pres_SetDrawColor( Pres_Color new_color );

// clears the window with clear color
void Pres_RenderClear()
{
	Pres_SetDrawColor( pres_clear_color );
	SDL_RenderClear( pres_main_renderer );
}

// renders a full scene
void Pres_RenderScene( Pres_Scene* scene )
{
	SDL_Rect rects[scene->len];
	Pres_RenderClear();
	
	for (size_t i = 0; i < scene->len; i++)
	{
		const Pres_Transform elm = scene->entities[i];
		rects[i] =  (SDL_Rect){ elm.x - 50, elm.y - 50, 100, 100 };
	}
	
	Pres_SetDrawColor( (Pres_Color){ 255, 0, 0, 255 } );
	SDL_RenderFillRects( pres_main_renderer, rects, scene->len );
	
	SDL_RenderPresent( pres_main_renderer );
}

// close the main window and clean all rendering stuff
void Pres_RendererQuit()
{
	SDL_DestroyWindow( pres_main_window );
	pres_main_window = NULL;

	SDL_DestroyRenderer( pres_main_renderer );
	pres_main_renderer = NULL;
	SDL_Quit();
}
