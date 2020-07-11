

#ifndef PRES_INTERNAL_H
#define PRES_INTERNAL_H

#include <SDL2/SDL.h>
#include "pres.h"

#define LOG_SDL_ERROR( notes ) fprintf( stderr,  "Oh Shit! SDL_ERROR at %s : %d: \n\t%s\n\t%s\n", __FILE__, __LINE__, SDL_GetError(), notes );

extern Pres_Window* pres_main_window;
extern Pres_Renderer* pres_main_renderer;
extern Pres_Color pres_clear_color;


inline void Pres_SetClearColor( Pres_Color new_color )
{ pres_clear_color = new_color; }

inline void Pres_SetDrawColor( Pres_Color new_color )
{ SDL_SetRenderDrawColor( pres_main_renderer, new_color.r, new_color.g, new_color.b, new_color.a ); }

#endif /* PRES_INTERNAL_H */