//=================================
// include guard
#ifndef _enums_h_
#define _enums_h_

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
    ATTR1,
    ATTR2,
    ATTR3,
    SWORD,
    HORSE,
    PARAM1,
    PARAM2,
    PARAM3
  };

  enum Directions {
    UP,
    LEFT,
    DOWN,
    RIGHT
  };
}

namespace BSPBuilding {

    enum OpCode {
        ANI,
        ANIEND,
        PROPS,
        PROPSEND,
        PARAMETERS,
        PARAMETERSEND,
        ATTRIBUTES,
        ATTRIBUTESEND,
        STRING,
        SPRITE,
        ATTACHSPRITE
    };

}
#endif
