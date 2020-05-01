#include <dependencies/SDL2/SDL.h> 

#include "include/constants.h"
#include "include/components/renderComponent.h"
#include "include/initRender.h"

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