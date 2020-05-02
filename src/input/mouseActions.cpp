#include <map>
#include <iostream>

#include <dependencies/SDL2/SDL.h> 

#include "include/enums.h"
#include "include/constants.h"
#include "include/components/gameObject.h"
#include "include/components/renderComponent.h"
#include "include/mouseActions.h"

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