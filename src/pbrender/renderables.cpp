#include <string>
#include <iostream>

#include <dependencies/SDL2/SDL_image.h> 

#include "include/constants.h"
#include "include/components/renderComponent.h"

#include "include/renderables.h"

using namespace RenderComponent;

std::vector<Renderable*> RenderableList::renderables;
std::map<std::string, SDL_Surface*> SurfaceList::surfaces;

namespace PbRender{

  Renderable createRenderable(std::string &fileName){
    Renderable *renderable = new Renderable;
    RenderableList::renderables.push_back(renderable);

    if(!SurfaceList::surfaces.count(fileName)){
      SDL_Surface* image = IMG_Load(fileName.c_str());
      SurfaceList::surfaces.insert({fileName, image}); 
    }

    // loads image to our graphics hardware memory. 
    renderable->sdlTexture = SDL_CreateTextureFromSurface(Render::sdlRenderer, SurfaceList::surfaces[fileName]); 
  
    // connects our texture with dest to control position 
    SDL_QueryTexture(renderable->sdlTexture, NULL, NULL, &renderable->sdlRect.w, &renderable->sdlRect.h); 
  
    renderable->sdlRect.x = (WIDTH - renderable->sdlRect.w) / 2; 
    renderable->sdlRect.y = (HEIGHT - renderable->sdlRect.h) / 2;

    renderable->srcRect.x = 0;
    renderable->srcRect.y = 0;
    renderable->srcRect.w = renderable->sdlRect.w;
    renderable->srcRect.h = renderable->sdlRect.h;

    return *renderable;
  }

  RenderComponent::Renderable createBlittedRenderable(std::string &fileName, std::string &blitName, int offX, int offY, int width, int height){
    Renderable *renderable = new Renderable;
    RenderableList::renderables.push_back(renderable);

    if(!SurfaceList::surfaces.count(fileName)){
      SDL_Surface* image = IMG_Load(fileName.c_str());
      SurfaceList::surfaces.insert({fileName, image}); 
    }

    if(!SurfaceList::surfaces.count(fileName + blitName)){
      SurfaceList::surfaces.insert({fileName + blitName, SurfaceList::surfaces[fileName]});
    }

    renderable->sdlTexture = SDL_CreateTextureFromSurface(Render::sdlRenderer, SurfaceList::surfaces[fileName+blitName]); 

    renderable->srcRect.x = offX;
    renderable->srcRect.y = offY;
    renderable->srcRect.w = width;
    renderable->srcRect.h = height;

    renderable->sdlRect.w = width;
    renderable->sdlRect.h = height;
  
    SDL_QueryTexture(renderable->sdlTexture, NULL, NULL, &width, &height); 
  
    renderable->sdlRect.x = (WIDTH - renderable->sdlRect.w) / 2; 
    renderable->sdlRect.y = (HEIGHT - renderable->sdlRect.h) / 2;

    return *renderable;
  }
}