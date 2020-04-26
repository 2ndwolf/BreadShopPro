//=================================
// include guard
#ifndef _ganiInformation_h_
#define _ganiInformation_h_

#include <vector>
#include <string>

#include "include/enums.h"

namespace GaniBuilding {
  class SpriteDef {
    public:
      int index{};
      std::string image;
      int offX{};
      int offY{};
      int width{};
      int height{};
      std::string name;
      DefaultImageType defaultImage = NOTDEFAULT;

      SpriteDef() = default;

      SpriteDef(int pIndex, std::string pImage, int pOffX, int pOffY, int pWidth, int pHeight, std::string pName) : index(pIndex), image(pImage), offX(pOffX), offY(pOffY), width(pWidth), height(pHeight), name(pName) {
        if (pImage == "SPRITES") {
          defaultImage = SPRITES;
        } else if (pImage == "SHIELD") {
          defaultImage = SHIELD;
        } else if (pImage == "HEAD") {
          defaultImage = HEAD;
        } else if (pImage == "BODY") {
          defaultImage = BODY;
        } else if (pImage == "ATTR1") {
          defaultImage = ATTR1;
        } else if (pImage == "ATTR2") {
          defaultImage = ATTR2;
        } else if (pImage == "ATTR3") {
          defaultImage = ATTR3;
        } else if (pImage == "SWORD") {
          defaultImage = SWORD;
        } else if (pImage == "HORSE") {
          defaultImage = HORSE;
        } else if (pImage == "PARAM1") {
          defaultImage = PARAM1;
        } else if (pImage == "PARAM2") {
          defaultImage = PARAM2;
        } else if (pImage == "PARAM3") {
          defaultImage = PARAM3;
        }
      };
  };

  class Sound {
    public:
      std::string fileName;
      int x{}, y{};

      Sound() = default;

      Sound(std::string &pFileName, double pX, double pY) : fileName(pFileName), x(static_cast<int>(pX * 16)), y(static_cast<int>(pY * 16)) {};
  };

  class AniSprite {
    public:
      int spriteIndex{}, x{}, y{}, layer{};

      AniSprite() = default;

      AniSprite(int pSpriteIndex, int pX, int pY, int pLayer) : spriteIndex(pSpriteIndex), x(pX), y(pY), layer(pLayer) {};
  };

  class AniDir {
    public:
      Directions direction{};
      std::vector<AniSprite> aniSprites;

      AniDir() = default;

      explicit AniDir(Directions pDirection) : direction(pDirection) {};
  };

  class AniFrame {
    public:
      std::vector<AniDir> aniDirs;
      int wait{};
      std::vector<Sound> sounds;

      AniFrame() = default;
  };

  class AttachedSprite {
    public:
      int spriteA{}, spriteB{}, relX{}, relY{};

      AttachedSprite() = default;

      AttachedSprite(int pSpriteA, int pSpriteB, int pRelX, int pRelY) : spriteA(pSpriteA), spriteB(pSpriteB), relX(pRelX), relY(pRelY) {};
  };

  class cGaniInformation {
    public:
      std::vector<SpriteDef> spriteDefs;
      std::vector<AniFrame> aniFrames;
      std::vector<Property> properties;
      std::vector<AttachedSprite> attachedSprites;
      std::vector<std::string> defaultAttributes;
      std::vector<std::string> defaultParameters;
      std::string defaultHead;
      std::string defaultBody;
      std::string nextGani = "none";

      cGaniInformation() = default;
  };
}
#endif
