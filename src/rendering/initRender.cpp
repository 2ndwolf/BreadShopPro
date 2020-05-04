#include <map>

#include <dependencies/SDL2/SDL.h> 
#include <dependencies/SDL2/SDL_image.h> 

#include "components/renderComponent.h"

#include "constants.h"

#include "rendering.h"

using namespace RenderComponent;

int Window::close;
SDL_Window *Render::sdlWindow;
SDL_Renderer *Render::sdlRenderer;
std::vector<Renderable*> RenderableList::renderables;
std::map<std::string, SDL_Surface*> SurfaceList::surfaces;


namespace Rendering {

  void initRender(){

    // returns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    } 
    Render::sdlWindow = SDL_CreateWindow("GAME",
                            SDL_WINDOWPOS_CENTERED, 
                            SDL_WINDOWPOS_CENTERED, 
                            WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE); 

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; 
  
    // creates a renderer to render our images 
    Render::sdlRenderer = SDL_CreateRenderer(Render::sdlWindow, -1, render_flags); 
  
  }

}