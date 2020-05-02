//=================================
// include guard
#ifndef _gameObjectComponent_h_
#define _gameObjectComponent_h_

#include <map>

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

}

#endif