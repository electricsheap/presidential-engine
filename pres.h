

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
typedef SDL_Window Pres_Window;
typedef SDL_Surface Pres_Surface;
typedef SDL_Renderer Pres_Renderer;
typedef SDL_Color Pres_Color;

int Pres_RendererInit( const char* title , Uint32 width, Uint32 height ); 	// create the main window and set up SDL
void Pres_RenderScene();
void Pres_RendererQuit();
#pragma endregion



#pragma region // Scene
typedef struct {
	float x, y;
} Pres_Transform;

typedef struct {
	Pres_Transform* entities;
	size_t len;
} Pres_Scene;
#pragma



#pragma region // Storage
typedef enum {
	Pres_VecStorage
} Pres_StorageType;
#pragma endregion // Storage


#pragma region // Events
void Pres_FlushEvents();
#pragma endregion






// TODO: Resource loading and management
// 		 possibly json parser 
#pragma region // Resources
int Pres_LoadResources();
#pragma endregion


#endif /* PRES_H */