
#include <map>
#include <iostream>

#include "dependencies/SDL2/SDL_scancode.h"

#include "include/constants.h"
#include "include/components/gameObject.h"
#include "include/components/renderComponent.h"

using namespace RenderComponent;
using namespace GameObjectComponent;

namespace Input{

  void updateSquare(){
    std::map<int, int>::iterator it = KeyStates::keycodeStates.begin();

    while (it != KeyStates::keycodeStates.end()){
      std::cout << it->second;
      if(it->first == SDL_SCANCODE_UP && it->second == 1){
        RenderableList::renderables[0]->sdlRect.y -= 300 / 30;
      }
      it++;
    }

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
  }

}
