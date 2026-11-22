#ifndef SDL_WRAPPER_H
#define SDL_WRAPPER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/* Define Constants */
constexpr int screenW{ 640 };
constexpr int screenH{ 480 };

/* Declare Prototypes*/
bool init();		// Initialize SDL and create window
bool loadMedia();	// Loads Media
void close();		// Frees Media and Shuts Down SDL

/* Declare Global Variables */
SDL_Window* gWindow{ nullptr };			//Render Window Pointer
SDL_Surface* gScrSurface{ nullptr };	//Screeen Surface Pointer
SDL_Surface* gImgExample{ nullptr };	//Image Surface Pointer

bool init() {
	bool success{ true };
	if (SDL_Init(SDL_INIT_VIDEO) == false) {	//Error Check
		SDL_Log("SDL failed to Initialize! SDLErr: %s\n", SDL_GetError());
		success = false; //Set Error Flag
	} else { //Create Window
		if (gWindow = SDL_CreateWindow("Yggdrasil", screenW, screenH, 0); gWindow == nullptr) {
			SDL_Log("SDL failed to Create Window! SDLErr: %s\n", SDL_GetError());
			success = false;
		} else { //Assign Window Surface
			gScrSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia() {
	bool success{ true };

	return success;
}

void close() {
	SDL_DestroySurface(gImgExample);
	gImgExample = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gScrSurface = nullptr;

	SDL_Quit();
}

#endif
