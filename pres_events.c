

#include "pres.h"
#include "pres_internal.h"


void Pres_FlushEvents()
{

	while( SDL_PollEvent( &(SDL_Event){ 0 } ) )
	{}
}