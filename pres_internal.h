

#ifndef PRES_INTERNAL_H
#define PRES_INTERNAL_H

#include <SDL2/SDL.h>
#include "pres.h"

#define LOG_SDL_ERROR( notes ) fprintf( stderr,  "Oh Shit! SDL_ERROR at %s : %d: \n\t%s\n\t%s\n", __FILE__, __LINE__, SDL_GetError(), notes );

extern PRES_Window* pres_main_window;
extern PRES_Renderer* pres_main_renderer;
extern PRES_Color pres_clear_color;


inline void PRES_SetClearColor( PRES_Color new_color )
{ pres_clear_color = new_color; }

inline void PRES_SetDrawColor( PRES_Color new_color )
{ SDL_SetRenderDrawColor( pres_main_renderer, new_color.r, new_color.g, new_color.b, new_color.a ); }

#endif /* PRES_INTERNAL_H */