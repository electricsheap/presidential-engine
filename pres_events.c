

#include "pres.h"
#include "pres_internal.h"


void PRES_FlushEvents()
{

	while( SDL_PollEvent( &(SDL_Event){ 0 } ) )
	{}
}