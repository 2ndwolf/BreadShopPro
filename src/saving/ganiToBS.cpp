
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include "src/components/ganiInformation.h"
// #include "save.h"

using namespace std;
using namespace GaniBuilding;

namespace Saving {

  void ganiToBS(GaniInformation aniInfo, string fileName, string as){
    
    ofstream outFile(fileName + "." + as, ios::out);

    vector<string> fileLines;

    if(as == "gani"){
      fileLines.push_back("GANI0001");
    } else if (as == "bs"){
      fileLines.push_back("BSv01");
    }

    for(SpriteDef def : aniInfo.spriteDefs){
      string defLine = 
      "SPRITE " + 
      to_string(def.index) + ' ' + 
      def.image + ' ' + 
      to_string(def.offX) + ' ' +
      to_string(def.offY) + ' ' +
      to_string(def.width) + ' ' +
      to_string(def.height) + ' ' +
      def.name;

      fileLines.push_back(defLine);
    }

    for(AttachedSprite attached : aniInfo.attachedSprites){
      string attachLine =
      "ATTACHSPRITE " +
      to_string(attached.spriteA) + ' ' +
      to_string(attached.spriteB) + ' ' +
      to_string(attached.relX) + ' ' +
      to_string(attached.relY);

      fileLines.push_back(attachLine);
    }

    fileLines.push_back("");

    for(Property prop : aniInfo.properties){
      string propLine;
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
      fileLines.push_back(propLine);
    }

    for(int i = 0; i < aniInfo.defaultParameters.size(); i++){
      string paramLine = "DEFAULTPARAM" + to_string(i + 1) + " " + aniInfo.defaultParameters[i];
      fileLines.push_back(paramLine);
    }

    for(int i = 0; i < aniInfo.defaultAttributes.size(); i++){
      string attrLine = "DEFAULTATTR" + to_string(i + 1) + " " + aniInfo.defaultAttributes[i];
      fileLines.push_back(attrLine);
    }
    
    fileLines.push_back("DEFAULTHEAD " + aniInfo.defaultHead);
    fileLines.push_back("DEFAULTBODY " + aniInfo.defaultBody);

    fileLines.push_back("");
    fileLines.push_back("ANI");

    for(AniFrame frame : aniInfo.aniFrames){
      for(AniDir dir : frame.aniDirs){
        string dirLine;
        for(AniSprite sprite : dir.aniSprites){
          dirLine += to_string(sprite.spriteIndex) + " " + to_string(sprite.x) + " " + to_string(sprite.y) + ", ";
        }
        fileLines.push_back(dirLine);
      }
      if(frame.wait != 0){
        fileLines.push_back("WAIT " + to_string(frame.wait));
      }
      for(Sound sound : frame.sounds){
        string x = to_string(static_cast<double>(sound.x) / static_cast<double>(16));
        x.erase(x.find_last_not_of('0') + 1, string::npos);
        x.erase(x.find_last_not_of('.') + 1, string::npos);

        string y = to_string(static_cast<double>(sound.y) / static_cast<double>(16));
        y.erase(y.find_last_not_of('0') + 1, string::npos);
        y.erase(y.find_last_not_of('.') + 1, string::npos);

        fileLines.push_back("PLAYSOUND " + sound.fileName + " " + x + " " + y);
      }
      fileLines.push_back("");
    }

    fileLines.push_back("ANIEND");

    for(string line : fileLines){
      // line += "\n";
      // long size = line.size();
      // char* buffer = new char[size];
      // strcpy(buffer, line.c_str());
      outFile << line << "\n";
    }

    outFile.close();
    fileLines.clear();

  }

}