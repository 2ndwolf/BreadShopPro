#include <dependencies/SDL2/SDL.h> 

#include "include/constants.h"
#include "include/initRender.h"
#include "include/mouseInput.h"
#include "include/components/renderComponent.h"


using namespace RenderComponent;

namespace Input {

  int mouseInput () {
    SDL_Event event; 

    while (SDL_PollEvent(&event)) { 
      switch (event.type) { 

      case SDL_WINDOWEVENT:

        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
            // logFileStderr("MESSAGE:Resizing window...\n");
            // resizeWindow(event.window.data1, event.window.data2);
        }
          
        break;
      case SDL_QUIT: 
          // handling of close button 
        return 1;

      case SDL_KEYDOWN: 
          // keyboard API for key pressed 
        switch (event.key.keysym.scancode) { 
          case SDL_SCANCODE_W: 
          case SDL_SCANCODE_UP: 
            RenderableList::renderables[0]->sdlRect.y -= 300 / 30; 
            break; 
          case SDL_SCANCODE_A: 
          case SDL_SCANCODE_LEFT: 
            RenderableList::renderables[0]->sdlRect.x -= 300 / 30; 
            break; 
          case SDL_SCANCODE_S: 
          case SDL_SCANCODE_DOWN: 
            RenderableList::renderables[0]->sdlRect.y += 300 / 30; 
            break; 
          case SDL_SCANCODE_D: 
          case SDL_SCANCODE_RIGHT: 
            RenderableList::renderables[0]->sdlRect.x += 300 / 30; 
            break; 
        } 
      } 
    }
        // right boundary 

        if (RenderableList::renderables[0]->sdlRect.x + RenderableList::renderables[0]->sdlRect.w > WIDTH) 
            RenderableList::renderables[0]->sdlRect.x = HEIGHT - RenderableList::renderables[0]->sdlRect.w; 
  
        // left boundary 
        if (RenderableList::renderables[0]->sdlRect.x < 0) 
            RenderableList::renderables[0]->sdlRect.x = 0; 
  
        // bottom boundary 
        if (RenderableList::renderables[0]->sdlRect.y + RenderableList::renderables[0]->sdlRect.h > WIDTH) 
            RenderableList::renderables[0]->sdlRect.y = HEIGHT - RenderableList::renderables[0]->sdlRect.h; 
  
        // upper boundary 
        if (RenderableList::renderables[0]->sdlRect.y < 0) 
            RenderableList::renderables[0]->sdlRect.y = 0; 
    return 0;
  } 
}