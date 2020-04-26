#include "save.h"
#include <map>

using namespace std;
using namespace GaniBuilding;
using namespace BSPBuilding;

namespace Saving {


  void save(GaniInformation aniInfo, CString fileName, CString as){
    map<CString,int> strings;
    CString fileLines;
    if (as == "bytes"){
      char binaryFormatVersion = 1;
      fileLines.write("BSP");
      fileLines.writeChar(binaryFormatVersion);
      CString fileLines2;

      int stringIndex = 0;
      for (const SpriteDef &definition : aniInfo.spriteDefs) {
        if (strings.find(definition.image) == strings.end()) {
          fileLines2 >> char(OpCode::STRING) >> short(stringIndex) >> char(definition.image.trim().length())
                     << definition.image.trim();
          strings[definition.image] = stringIndex;
          stringIndex++;
        }
      }

      for (const SpriteDef &definition : aniInfo.spriteDefs) {
        if (strings.find(definition.name) == strings.end()) {
          fileLines2 >> char(OpCode::STRING) >> short(stringIndex) >> char(definition.name.trim().length())
                     << definition.name.trim();
          strings[definition.name] = stringIndex;
          stringIndex++;
        }
      }

      for (const SpriteDef &definition : aniInfo.spriteDefs) {
        fileLines2.writeChar(OpCode::SPRITE);
        fileLines2.writeShort(definition.index);
        fileLines2 >> short(strings[definition.image]);//char(definition.image.trim().length()) << definition.image.trim();
        fileLines2.writeChar(definition.offX);
        fileLines2.writeChar(definition.offY);
        fileLines2.writeShort(definition.width);
        fileLines2.writeShort(definition.height);
        fileLines2 >> short(strings[definition.name]);//char(definition.name.trim().length()) << definition.name.trim();
      }

      for (AttachedSprite attached : aniInfo.attachedSprites) {
        fileLines2.writeChar(OpCode::ATTACHSPRITE);
        fileLines2.writeShort(attached.spriteA);
        fileLines2.writeShort(attached.spriteB);
        fileLines2.writeChar(attached.relX);
        fileLines2.writeChar(attached.relY);
      }

      fileLines2.writeChar(OpCode::PROPS);
      for (Property prop : aniInfo.properties) {
        fileLines2.writeChar(prop);
        if (prop == SETBACKTO) {
          fileLines2 >> char(aniInfo.nextGani.length()) << aniInfo.nextGani;
        }
      }
      fileLines2.writeChar(OpCode::PROPSEND);

      fileLines2.writeChar(OpCode::PARAMETERS);
      for (int i = 0; i < aniInfo.defaultParameters.size(); i++) {
        CString paramLine = "DEFAULTPARAM" + to_string(i + 1);
        fileLines2 >> char(paramLine.length()) << paramLine >> char(aniInfo.defaultParameters[i].length()) << aniInfo.defaultParameters[i];
      }
      fileLines2.writeChar(OpCode::PARAMETERSEND);

      fileLines2.writeChar(OpCode::ATTRIBUTES);
      for (int i = 0; i < aniInfo.defaultAttributes.size(); i++) {
        CString attrLine = "DEFAULTATTR" + to_string(i + 1);
        fileLines2 >> char(attrLine.length()) << attrLine >> char(aniInfo.defaultAttributes[i].length()) << aniInfo.defaultAttributes[i];
      }

      CString defaultHeadAttr = "DEFAULTHEAD";
      fileLines2 >> char(defaultHeadAttr.length()) << defaultHeadAttr >> char(aniInfo.defaultHead.length()) << aniInfo.defaultHead;
      CString defaultBodyAttr = "DEFAULTBODY";
      fileLines2 >> char(defaultBodyAttr.length()) << defaultBodyAttr >> char(aniInfo.defaultBody.length()) << aniInfo.defaultBody;
      fileLines2.writeChar(OpCode::ATTRIBUTESEND);

      fileLines2.writeChar(OpCode::ANI);
      fileLines2.writeChar(OpCode::ANIEND);

      fileLines << fileLines2.zcompress();

    } else {
      if (as == "gani") {
        fileLines.write("GANI0001");
      } else if (as == "bs") {
        fileLines.write("BSv01");
      }

      fileLines.write('\n');

      for (const SpriteDef &def : aniInfo.spriteDefs) {
        CString defLine =
                "SPRITE " +
                to_string(def.index) + ' ' +
                def.image + ' ' +
                to_string(def.offX) + ' ' +
                to_string(def.offY) + ' ' +
                to_string(def.width) + ' ' +
                to_string(def.height) + ' ' +
                def.name;

        fileLines.write(defLine << '\n');
      }

      for (AttachedSprite attached : aniInfo.attachedSprites) {
        CString attachLine =
                "ATTACHSPRITE " +
                to_string(attached.spriteA) + ' ' +
                to_string(attached.spriteB) + ' ' +
                to_string(attached.relX) + ' ' +
                to_string(attached.relY);

        fileLines.write(attachLine << '\n');
      }

      fileLines.write('\n');

      for (Property prop : aniInfo.properties) {
        CString propLine;
        if (prop == CONTINUOUS) {
          propLine = "CONTINUOUS";
        } else if (prop == LOOP) {
          propLine = "LOOP";
        } else if (prop == SINGLEDIRECTION) {
          propLine = "SINGLEDIRECTION";
        } else if (prop == SETBACKTO) {
          propLine = "SETBACKTO";
          propLine += " ";
          propLine += aniInfo.nextGani;
        }
        fileLines.write(propLine << '\n');
      }

      for (int i = 0; i < aniInfo.defaultParameters.size(); i++) {
        CString paramLine = "DEFAULTPARAM" + to_string(i + 1) + " " + aniInfo.defaultParameters[i];
        fileLines.write(paramLine << '\n');
      }

      for (int i = 0; i < aniInfo.defaultAttributes.size(); i++) {
        CString attrLine = "DEFAULTATTR" + to_string(i + 1) + " " + aniInfo.defaultAttributes[i];
        fileLines.write(attrLine << '\n');
      }

      fileLines.write(CString("DEFAULTHEAD " + aniInfo.defaultHead) << '\n');
      fileLines.write(CString("DEFAULTBODY " + aniInfo.defaultBody) << '\n');

      fileLines.write('\n');
      fileLines.write(CString("ANI") << '\n');

      for (const AniFrame &frame : aniInfo.aniFrames) {
        for (auto &dir : frame.aniDirs) {
          CString dirLine;
          for (AniSprite sprite : dir.aniSprites) {
            dirLine << to_string(sprite.spriteIndex) + " " + to_string(sprite.x) + " " + to_string(sprite.y) + ", ";
          }
          fileLines.write(dirLine << '\n');
        }
        if (frame.wait != 0) {
          fileLines.write(CString("WAIT " + to_string(frame.wait)) << '\n');
        }
        for (const Sound &sound : frame.sounds) {
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
    }

    fileLines.save(CString() << fileName << "." << as);

    fileLines.clear();
  }

}
