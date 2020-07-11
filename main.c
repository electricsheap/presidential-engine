
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


#include "pres.h"

static const uint32_t SCREEN_WIDTH = 640;
static const uint32_t SCREEN_HEIGHT = 480;

int main() 
{
	PRES_RendererInit( "hello", SCREEN_WIDTH, SCREEN_HEIGHT );
	PRES_SetRenderClear( (PRES_Color){ 255, 255, 255, 255 } );
	PRES_FlushEvents();
	PRES_RenderScene();

	sleep( 5 );
	// SDL_Delay( 10000 );
	return 0;
}

