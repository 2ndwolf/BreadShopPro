//=================================
// include guard
#ifndef _ganiInformation_h_
#define _ganiInformation_h_

#include "enums.h"

#include <vector>
#include <string>

using namespace std;


namespace GaniBuilding {

  class SpriteDef{
    public:
      int index;
      string image;
      int offX;
      int offY;
      int width;
      int height;
      string name;
      DefaultImageType defaultImage = NOTDEFAULT;

      SpriteDef();

      SpriteDef(int pIndex, string pImage, int pOffX, int pOffY, int pWidth, int pHeight, string pName);
  };

  class Sound{
    public:
      string fileName;
      int x{}, y{};

      Sound();

      Sound(string& pFileName, double pX, double pY);
  };

  class AniSprite{
    public:
      int spriteIndex{}, x{}, y{} , layer{};

    AniSprite();

    AniSprite(int pSpriteIndex, int pX, int pY, int pLayer);

  };

  class AniDir {
    public:
      Directions direction;
      vector<AniSprite> aniSprites;

      AniDir() = default;

      AniDir(Directions pDirection);
  };

  class AniFrame {
    public:
      vector<AniDir> aniDirs;
      int wait{};
      vector<Sound> sounds;

      AniFrame();

  };

  class AttachedSprite{
    public:
      int spriteA{}, spriteB{}, relX{}, relY{};

      AttachedSprite();

      AttachedSprite(int pSpriteA, int pSpriteB, int pRelX, int pRelY);
  };

  class GaniInformation {
    public:
      vector<SpriteDef> spriteDefs;
      vector<AniFrame> aniFrames;
      vector<Property> properties;
      vector<AttachedSprite> attachedSprites;
      vector<string> defaultAttributes;
      string defaultHead;
      string defaultBody;
      string nextGani = "none";

      GaniInformation();
  };
}
#endif