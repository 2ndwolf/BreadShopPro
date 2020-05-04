#include <map>
#include <iostream>

#include <dependencies/SDL2/SDL.h> 

#include "components/renderComponent.h"
#include "components/gameObject.h"

#include "enums.h"
#include "constants.h"

#include "input.h"

using namespace GameObjectComponent;
using namespace RenderComponent;

namespace Input {
  
  void updateMouse(){
    if(Mouse::clicks[SDL_BUTTON_LEFT] > 0){

      RenderableList::renderables[0]->sdlRect.x = Mouse::x;
      RenderableList::renderables[0]->sdlRect.y = Mouse::y;
    }
  }

}