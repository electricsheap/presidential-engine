

#include <stdlib.h>

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

#include "pres.h"
#include "pres_internal.h"


static void** resources = NULL;

// char*[] = char**
int Pres_LoadResources( const char** resource_paths, size_t resource_count )
{
	resources = malloc( sizeof(void*) * resource_count );
	
	return 0;
}


void* Pres_GetResource( size_t which )
{
	return malloc(1);
}