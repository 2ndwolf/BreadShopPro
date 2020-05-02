//=================================
// include guard
#ifndef _enums_h_
#define _enums_h_

#include <cstddef>

namespace GaniBuilding {
  enum Property {
    CONTINUOUS,
    LOOP,
    SINGLEDIRECTION,
    SETBACKTO
  };

  enum DefaultImageType {
    NOTDEFAULT,
    SPRITES,
    SHIELD,
    HEAD,
    BODY,
    SWORD,
    HORSE,
    PARAM1,
    ATTR1,
    PARAM2,
    ATTR2,
    PARAM3,
    ATTR3
  };

  enum Directions {
    UP,
    LEFT,
    DOWN,
    RIGHT
  };

}

namespace Enumerators {
  enum FileTypes {
    GANI,//Old file format
    BS,  //Restructured Gani
    BSP, //Encrypted BS file with bundled images
    SBSP //BSP file without images
  };

  enum WaitState{
    WAIT,
    DONE,
    STANDBY
  };
}

  enum MouseMode{
    DEFAULT
  };

#endif
