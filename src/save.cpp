#include <CString.h>

#include "ganiInformation.h"

using namespace std;
using namespace GaniBuilding;

namespace Saving {

  void save(GaniInformation aniInfo, const string& fileName, const string& as){

    CString fileLines;

    if(as == "gani"){
      fileLines.write("GANI0001");
    } else if (as == "bs"){
      fileLines.write("BSv01");
    }

    fileLines.write('\n');

    for(const SpriteDef& def : aniInfo.spriteDefs){
      CString defLine =
      "SPRITE " +
      to_string(def.index) + ' ' +
      def.image + ' ' +
      to_string(def.offX) + ' ' +
      to_string(def.offY) + ' ' +
      to_string(def.width) + ' ' +
      to_string(def.height) + ' ' +
      def.name;

      fileLines.write( defLine << '\n');
    }

    for(AttachedSprite attached : aniInfo.attachedSprites){
      CString attachLine =
      "ATTACHSPRITE " +
      to_string(attached.spriteA) + ' ' +
      to_string(attached.spriteB) + ' ' +
      to_string(attached.relX) + ' ' +
      to_string(attached.relY);

      fileLines.write(attachLine << '\n');
    }

    fileLines.write('\n');

    for(Property prop : aniInfo.properties){
      CString propLine;
      if(prop == CONTINUOUS){
        propLine = "CONTINUOUS";
      } else if (prop == LOOP){
        propLine = "LOOP";
      } else if (prop == SINGLEDIRECTION){
        propLine = "SINGLEDIRECTION";
      } else if (prop == SETBACKTO){
        propLine = "SETBACKTO";
        propLine += " ";
        propLine += aniInfo.nextGani;
      }
      fileLines.write(propLine << '\n');
    }

    for(int i = 0; i < aniInfo.defaultParameters.size(); i++){
      CString paramLine = "DEFAULTPARAM" + to_string(i + 1) + " " + aniInfo.defaultParameters[i];
      fileLines.write(paramLine << '\n');
    }

    for(int i = 0; i < aniInfo.defaultAttributes.size(); i++){
      CString attrLine = "DEFAULTATTR" + to_string(i + 1) + " " + aniInfo.defaultAttributes[i];
      fileLines.write(attrLine << '\n');
    }

    fileLines.write(CString("DEFAULTHEAD " + aniInfo.defaultHead) << '\n');
    fileLines.write(CString("DEFAULTBODY " + aniInfo.defaultBody) << '\n');

    fileLines.write('\n');
    fileLines.write(CString("ANI")<< '\n');

    for(const AniFrame& frame : aniInfo.aniFrames){
      for(const AniDir& dir : frame.aniDirs){
        CString dirLine;
        for(AniSprite sprite : dir.aniSprites){
          dirLine << to_string(sprite.spriteIndex) + " " + to_string(sprite.x) + " " + to_string(sprite.y) + ", ";
        }
        fileLines.write(dirLine << '\n');
      }
      if(frame.wait != 0){
        fileLines.write(CString("WAIT " + to_string(frame.wait)) << '\n');
      }
      for(const Sound& sound : frame.sounds){
        string x = to_string(static_cast<double>(sound.x) / static_cast<double>(16));
        x.erase(x.find_last_not_of('0') + 1, string::npos);
        x.erase(x.find_last_not_of('.') + 1, string::npos);

        string y = to_string(static_cast<double>(sound.y) / static_cast<double>(16));
        y.erase(y.find_last_not_of('0') + 1, string::npos);
        y.erase(y.find_last_not_of('.') + 1, string::npos);

        fileLines.write(CString("PLAYSOUND " + sound.fileName + " " + x + " " + y) << '\n');
      }
      fileLines.write('\n');
    }

    fileLines.write(CString("ANIEND") << '\n');

    fileLines.save(fileName + "." + as);

    fileLines.clear();
  }

}
