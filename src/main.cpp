/** Program Entry Point
 *      By: Jayson S. (http://gsgstudio.online)
*/

/* Declare PreProcessors and Libraries */
#include <iostream>
#include <string>

#include "../SDLWrapper.h"

//Using Standard Namespace
using namespace std;

int main(int argc, char* argv[]) {
    int exitCode{ 0 };

    if (init() == false) {
        SDL_Log("Unable to Initialize Program!\n");
        exitCode = 1;
    } else {
        bool quit{ false };

        SDL_Event e; //Event Handler/Container
        SDL_zero(e);

        while (quit == false) {
            while (SDL_PollEvent(&e) == true) {
                if (e.type == SDL_EVENT_QUIT) {
                    quit = true;
                }
            }

            SDL_FillSurfaceRect(gScrSurface, nullptr, SDL_MapSurfaceRGB(gScrSurface, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(gWindow);
        }
    }

    close();
    return exitCode;
}