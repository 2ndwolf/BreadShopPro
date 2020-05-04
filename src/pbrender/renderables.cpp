#include <string>
#include <iostream>

#include <dependencies/SDL2/SDL_image.h> 

#include "components/renderComponent.h"

#include "constants.h"

#include "pbrender.h"

using namespace RenderComponent;



namespace PbRender{
  int i = 0;

  RenderComponent::Renderable createRenderable(std::string &fileName, int offX, int offY, int width, int height){
    Renderable *renderable = new Renderable;
    RenderableList::renderables.push_back(renderable);

    if(!SurfaceList::surfaces.count(fileName)){
      SDL_Surface* image = IMG_Load(fileName.c_str());
      SurfaceList::surfaces.insert({fileName, image}); 
    }

    // loads image to our graphics hardware memory. 
    renderable->sdlTexture = SDL_CreateTextureFromSurface(Render::sdlRenderer, SurfaceList::surfaces[fileName]); 
  
    renderable->srcRect.x = offX;
    renderable->srcRect.y = offY;

    if(width != 0 && height != 0){
      renderable->srcRect.w = width;
      renderable->srcRect.h = height;
      renderable->sdlRect.w = width;
      renderable->sdlRect.h = height;
      SDL_QueryTexture(renderable->sdlTexture, NULL, NULL, &width, &height); 
    } else {
      SDL_QueryTexture(renderable->sdlTexture, NULL, NULL, &renderable->sdlRect.w, &renderable->sdlRect.h); 
      renderable->srcRect.w = renderable->sdlRect.w;
      renderable->srcRect.h = renderable->sdlRect.h;
    }
  
    renderable->sdlRect.x = (WIDTH  - renderable->sdlRect.w) / 2 + i * 30; 
    renderable->sdlRect.y = (HEIGHT - renderable->sdlRect.h) / 2 + i * 30;
    i++;


    return *renderable;
  }

}