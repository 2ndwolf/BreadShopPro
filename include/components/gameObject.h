//=================================
// include guard
#ifndef _gameObjectComponent_h_
#define _gameObjectComponent_h_

#include <map>

#include "include/enums.h"


namespace GameObjectComponent {

  class Position{
    int x, y, screenX, screenY;
  };

  class Bounds{
    int width, height;
  };

  class Direction{
    int dir;
  };

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
}

#endif