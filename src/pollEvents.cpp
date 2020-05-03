#include <iostream>

#include <dependencies/SDL2/SDL.h> 

#include "include/constants.h"
#include "include/initRender.h"
#include "include/mouseActions.h"
#include "include/components/renderComponent.h"

#include "include/pollEvents.h"


using namespace RenderComponent;

int Mouse::x;
int Mouse::y;
std::map<int, int> Mouse::clicks;
MouseMode Mouse::mouseMode = MouseMode::DEFAULT;
std::map<int, int> GameObjectComponent::KeyStates::keycodeStates;

namespace Events {

  int pollEvents () {
    SDL_Event event;

    // Increment pressed state, or -1 if released during previous frame
    updateInputStates(Mouse::clicks);
    updateInputStates(KeyStates::keycodeStates);

    while (SDL_PollEvent(&event)) { 
      switch (event.type) { 

      case SDL_WINDOWEVENT:

        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
            // logFileStderr("MESSAGE:Resizing window...\n");
            // resizeWindow(event.window.data1, event.window.data2);
        }
          
        break;
      case SDL_QUIT: 
        return 1;

      case SDL_KEYDOWN: 
        KeyStates::keycodeStates.insert({event.key.keysym.scancode, 1}); 
        break;

      case SDL_KEYUP:
        KeyStates::keycodeStates[event.key.keysym.scancode] = -1;
        break;

      case SDL_MOUSEBUTTONDOWN:
        switch(event.button.button){
          case SDL_BUTTON_LEFT:
            Mouse::clicks[SDL_BUTTON_LEFT] =  1;
            break;
          case SDL_BUTTON_RIGHT:
            Mouse::clicks[SDL_BUTTON_RIGHT] =  1;
            break;
        }

        break;

      case SDL_MOUSEBUTTONUP:
        switch(event.button.button){
          case SDL_BUTTON_LEFT:
            Mouse::clicks[SDL_BUTTON_LEFT] = -1;
          break;
          case SDL_BUTTON_RIGHT:
            Mouse::clicks[SDL_BUTTON_RIGHT] = -1;
          break;
        }
        break;

      case SDL_MOUSEMOTION:
        Mouse::x = event.motion.x;
        Mouse::y = event.motion.y;
        break;
      }
    }

    // Input::updateMouse();

    return 0;
  }

  void updateInputStates(std::map<int, int> &inputStates){
    std::map<int, int>::iterator it = inputStates.begin();
    while (it != inputStates.end()){

      if(it -> second == 1){
        it->second = 2;

      } else if (it -> second == -1){
        it = inputStates.erase(it);
        continue;
      }

      it++;

    }
  }
}
