
#include <map>
#include <iostream>
#include <algorithm>

#include "dependencies/SDL2/SDL_scancode.h"

#include "components/gameObject.h"
#include "components/renderComponent.h"
#include "components/customize.h"

#include "constants.h"

#include "input.h"

using namespace RenderComponent;
using namespace GameObjectComponent;
using namespace CustomizeComponent;

namespace Input{

  void updateSquare(){
    // If has selected flag
    std::map<int, int>::iterator it = KeyStates::keycodeStates.begin();

    while (it != KeyStates::keycodeStates.end()){
        std::cout << it->second;
      if(std::find(Keybinds::keys["UP"].begin(),
          Keybinds::keys["UP"].end(), it->first) != Keybinds::keys["UP"].end() && it->second == 1){
        RenderableList::renderables[0]->sdlRect.y -= 1;
      } else if(std::find(Keybinds::keys["DOWN"].begin(),
          Keybinds::keys["DOWN"].end(), it->first) != Keybinds::keys["DOWN"].end() && it->second == 1){
        RenderableList::renderables[0]->sdlRect.y += 1;
      }
      if(std::find(Keybinds::keys["LEFT"].begin(),
          Keybinds::keys["LEFT"].end(), it->first) != Keybinds::keys["LEFT"].end() && it->second == 1){
        RenderableList::renderables[0]->sdlRect.x -= 1;
      } else if(std::find(Keybinds::keys["RIGHT"].begin(),
          Keybinds::keys["RIGHT"].end(), it->first) != Keybinds::keys["RIGHT"].end() && it->second == 1){
        RenderableList::renderables[0]->sdlRect.x += 1;
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