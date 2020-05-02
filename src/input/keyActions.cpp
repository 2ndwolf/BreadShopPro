#include <map>

#include <dependencies/SDL2/SDL.h> 

#include "include/constants.h"
#include "include/components/gameObject.h"


using namespace GameObjectComponent;

namespace Input {
  
  void keyDown(int keycode){
    KeyStates::keycodeStates.insert({keycode, 1}); 
  }

  void keyUp(int keycode){
    KeyStates::keycodeStates[keycode] = -1;
  }

  void updateKeyStates(){
    std::map<int, int>::iterator it = KeyStates::keycodeStates.begin();
    while (it != KeyStates::keycodeStates.end()){

      if(it -> second == 1){
        it->second = 2;

      } else if (it -> second == -1){
        it = KeyStates::keycodeStates.erase(it);
        continue;
      }

      it++;

    }
  }

}