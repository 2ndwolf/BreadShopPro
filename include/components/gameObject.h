//=================================
// include guard
#ifndef _gameObjectComponent_h_
#define _gameObjectComponent_h_

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

  
}

#endif