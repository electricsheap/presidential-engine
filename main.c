
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

int main( int argc, char* argv[] ) 
{
	Transform trans[] = { { 100, 100 }, { 200, 200 }, { 300, 300 }, { 400, 400 } };
	Scene scene = {
		.entities = trans,
		.len = 4
	};

	Pres_RendererInit( "hello", SCREEN_WIDTH, SCREEN_HEIGHT );
	Pres_FlushEvents();
	Pres_RenderScene( &scene );

	getc( stdin );
	Pres_RendererQuit();
	return 0;
}

