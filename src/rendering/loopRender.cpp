#include <dependencies/SDL2/SDL.h> 

#include "include/constants.h"
#include "include/components/renderComponent.h"
#include "include/initRender.h"

using namespace RenderComponent;

namespace Rendering {
  
  void loopRender(){
    // clears the screen 
    SDL_RenderClear(Render::sdlRenderer); 

    for(int i = 0; i < RenderableList::renderables.size(); i++){
      SDL_RenderCopy(Render::sdlRenderer, RenderableList::renderables[i]->sdlTexture, &RenderableList::renderables[i]->srcRect, &RenderableList::renderables[i]->sdlRect); 
    }
    // triggers the double buffers 
    // for multiple rendering 
    SDL_RenderPresent(Render::sdlRenderer); 

    // calculates to 60 fps 
    SDL_Delay(1000 / 60); 
  }

}