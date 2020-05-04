#include <dependencies/SDL2/SDL.h> 

#include "components/renderComponent.h"

#include "constants.h"

#include "rendering.h"

using namespace RenderComponent;

namespace Rendering {
  
  void killRender(){
    // destroy texture
    RenderableList *renderableList;
    for(int i = 0; i < RenderableList::renderables.size(); i++){
      SDL_DestroyTexture(RenderableList::renderables[i]->sdlTexture); 
    }

    std::map<std::string, SDL_Surface*>::iterator it = SurfaceList::surfaces.begin();
    while (it != SurfaceList::surfaces.end()){
      SDL_FreeSurface(it->second); 
      it++;
    }

    // destroy renderer 
    SDL_DestroyRenderer(Render::sdlRenderer); 

    // destroy window 
    SDL_DestroyWindow(Render::sdlWindow); 
  }

}