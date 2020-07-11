

#ifndef PRES_INTERNAL_H
#define PRES_INTERNAL_H

#include <SDL2/SDL.h>
#include "pres.h"


extern PRES_Window* pres_main_window;

#define LOG_SDL_ERROR( notes ) fprintf( stderr,  "Oh Shit! SDL_ERROR at %s : %d: \n\t%s\n\t%s\n", __FILE__, __LINE__, SDL_GetError(), notes );

#endif /* PRES_INTERNAL_H */