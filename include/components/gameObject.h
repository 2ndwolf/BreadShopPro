//=================================
// include guard
#ifndef _gameObjectComponent_h_
#define _gameObjectComponent_h_

#include <map>

#include "include/enums.h"
#include "include/components/basics.h"


namespace GameObjectComponent {

  // Single component services as classes
  class KeyStates{
    public:
    static std::map<int, int> keycodeStates;
  };

  class Mouse{
    public:
    static int x, y;
    static std::map<int, int> clicks;
    static MouseMode mouseMode;
  };

  // Realistic components
  struct Bounds{
    Size size;
  };

  struct Direction{
    int dir;
  };
  
}

#endif