

#ifndef PRES_H
#define PRES_H

#include <stdbool.h>
#include <sys/types.h>

#include <SDL2/SDL.h>


#pragma region // Types
typedef	int8_t		Int8;
typedef uint8_t		Uint8;
typedef int16_t		Int16;
typedef uint16_t	Uint16;
typedef int32_t		Int32;
typedef uint32_t	Uint32;
typedef int64_t		Int64;
typedef uint64_t	Uint64;
typedef float		Float32;
typedef double		Float64;
#pragma endregion






#pragma region // Renderer
typedef SDL_Window PRES_Window;
typedef SDL_Surface PRES_Surface;
typedef SDL_Renderer PRES_Renderer;
typedef SDL_Color PRES_Color;

int PRES_RendererInit( const char* title , Uint32 width, Uint32 height ); 	// create the main window and set up SDL
void PRES_RenderScene(); 					// clears the window
void PRES_RendererQuit(); 					// quit the main window and clean renderer stuff
#pragma endregion







#pragma region // Events
void PRES_FlushEvents();
#pragma endregion






// TODO: Resource loading and management
// 		 possibly json parser 
#pragma region // Resources
int PRES_LoadResources();
#pragma endregion


#endif /* PRES_H */