
#include <map>
#include <string>

#include "dependencies/SDL2/SDL_scancode.h"

#include "include/components/customize.h"


using namespace CustomizeComponent;

std::map<std::string, std::vector<SDL_Scancode>> Keybinds::keys;

namespace Input{

  void initKeyBinds(){
    // Take keybinds from user preferences
    Keybinds::keys["UP"] = {SDL_SCANCODE_UP, SDL_SCANCODE_W};
    Keybinds::keys["LEFT"] = {SDL_SCANCODE_LEFT, SDL_SCANCODE_A};
    Keybinds::keys["DOWN"] = {SDL_SCANCODE_DOWN, SDL_SCANCODE_S};
    Keybinds::keys["RIGHT"] = {SDL_SCANCODE_RIGHT, SDL_SCANCODE_D};
  }

}