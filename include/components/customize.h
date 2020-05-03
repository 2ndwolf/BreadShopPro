//=================================
// include guard
#ifndef _customize_h_
#define _customize_h_

#include <string>
#include <vector>
#include <map>

#include "dependencies/SDL2/SDL_scancode.h"

namespace CustomizeComponent {

  class ImageList{
    public:
    std::map<std::string, std::string> images;
  };
  
  struct Custom{
    ImageList playerCharacter;
    ImageList gui;
    ImageList hud;
    ImageList world;
  };


  class Keybinds{
    public:
    static std::map<std::string, std::vector<SDL_Scancode>> keys;
  };

}

#endif