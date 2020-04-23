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

      SpriteDef(){ }

      SpriteDef(int pIndex, string pImage, int pOffX, int pOffY, int pWidth, int pHeight, string pName){
        index = pIndex;
        image = pImage;

        offX = pOffX;
        offY = pOffY;
        width = pWidth;
        height = pHeight;
        name = pName;

        if(pImage == "SPRITES"){
          defaultImage = SPRITES;
        } else if(pImage == "SHIELD"){
          defaultImage = SHIELD;
        } else if(pImage == "HEAD"){
          defaultImage = HEAD;
        } else if(pImage == "BODY"){
          defaultImage = BODY;
        } else if(pImage == "ATTR1"){
          defaultImage = ATTR1;
        } else if(pImage == "ATTR2"){
          defaultImage = ATTR2;
        } else if(pImage == "ATTR3"){
          defaultImage = ATTR3;
        } else if(pImage == "SWORD"){
          defaultImage = SWORD;
        } else if(pImage == "HORSE"){
          defaultImage = HORSE;
        } else if(pImage == "PARAM1"){
          defaultImage = PARAM1;
        } else if(pImage == "PARAM2"){
          defaultImage = PARAM2;
        } else if(pImage == "PARAM3"){
          defaultImage = PARAM3;
        }
      }
  };

  class Sound{
    public:
      string fileName;
      int x, y;

      Sound(){ }

      Sound(string& pFileName, double pX, double pY){
        fileName = pFileName;
        x = static_cast<int>(pX * 16);
        y = static_cast<int>(pY * 16);
      }
  };

  class AniSprite{
    public:
      int spriteIndex, x, y , layer;

    AniSprite() {}

    AniSprite(int pSpriteIndex, int pX, int pY, int pLayer){
      spriteIndex = pSpriteIndex;
      x = pX;
      y = pY;
      layer = pLayer;
    }

  };

  class AniDir {
    public:
      Directions direction;
      vector<AniSprite> aniSprites;

      AniDir(){}

      AniDir(Directions pDirection){
        direction = pDirection;
      }
  };

  class AniFrame {
    public:
      vector<AniDir> aniDirs;
      int wait;
      vector<Sound> sounds;

      AniFrame() { }

  };

  class AttachedSprite{
    public:
      int spriteA, spriteB, relX, relY;

      AttachedSprite(){}

      AttachedSprite(int pSpriteA, int pSpriteB, int pRelX, int pRelY){
        spriteA = pSpriteA;
        spriteB = pSpriteB;
        relX = pRelX;
        relY = pRelY;
      }
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

      GaniInformation(){}
  };
}