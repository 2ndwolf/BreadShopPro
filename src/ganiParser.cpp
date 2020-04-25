#include <iostream>
#include <vector>
#include <string>
#include <CString.h>

#include "ganiInformation.h"
#include "utils.h"
#include "enums.h"
#include "ganiParser.h"

using namespace std;
using namespace GaniBuilding;

namespace GaniParsing {
  GaniInformation parse(CString lines) {
    bool isAni = false;
    int layer, direction;

    auto *currentGani = new GaniInformation();

    lines.removeAllI("\r");
    vector<CString> strList = lines.tokenize('\n', true);

    for (CString &line : strList) {
      
      if (!isAni) {
        vector<CString> splitLine = line.tokenize(" ");

        CString firstArgument = (!splitLine.empty())? splitLine[0] : "";

        if(firstArgument == "SPRITE") {
          CString spriteName;
          for (int i = 7; i < splitLine.size(); i++) {
            if(i != 7){
              spriteName << ' ';
            }
            spriteName << splitLine[i];
          }
          currentGani->spriteDefs.push_back(
                  SpriteDef(stoi(splitLine[1].text()), splitLine[2], stoi(splitLine[3].text()), stoi(splitLine[4].text()),
                            stoi(splitLine[5].text()), stoi(splitLine[6].text()), spriteName));
        } else if (firstArgument == "ATTACHSPRITE") {
          currentGani->attachedSprites.push_back(
                  AttachedSprite(stoi(splitLine[1].text()), stoi(splitLine[2].text()), stoi(splitLine[3].text()), stoi(splitLine[4].text())));
        } else if (firstArgument == "ANI") {
          isAni = true;
          direction = layer = 0;
          continue;

          // If not ANI or SPRITE and isAni is false, then it is a Property
        } else {
          if(firstArgument == "LOOP"){
            currentGani->properties.push_back(Property::LOOP);
          } else if (firstArgument == "CONTINUOUS") {
            currentGani->properties.push_back(Property::CONTINUOUS);
          } else if (firstArgument == "SETBACKTO") {
            currentGani->properties.push_back(Property::SETBACKTO);
            splitLine.erase(splitLine.begin());
            currentGani->nextGani = utils::concatenateSpacedFileName(splitLine);
          } else if (firstArgument == "SINGLEDIRECTION") {
            currentGani->properties.push_back(Property::SINGLEDIRECTION);

            // If none of the above, then it is a default
          } else {
            // ADD DEFAULTS
            if (firstArgument.find("DEFAULT") == 0) {

              // This assumes the default attributes are ordered
              if (firstArgument.find("DEFAULTATTR") == 0) {
                splitLine.erase(splitLine.begin());
                currentGani->defaultAttributes.push_back(
                        utils::concatenateSpacedFileName(splitLine)
                );

              } else if (firstArgument == "DEFAULTHEAD") {
                splitLine.erase(splitLine.begin());
                currentGani->defaultHead = utils::concatenateSpacedFileName(splitLine);

              } else if (firstArgument == "DEFAULTBODY") {
                splitLine.erase(splitLine.begin());
                currentGani->defaultBody = utils::concatenateSpacedFileName(splitLine);

              } else if (firstArgument.find("DEFAULTPARAM") == 0){
                splitLine.erase(splitLine.begin());
                currentGani->defaultParameters.push_back(
                        utils::concatenateSpacedFileName(splitLine)
                );
              }

              // If it's neither a SPRITE, ATTACHEDSPRITE, property or DEFAULT,
              // and is not part of the animation, then it is an
              // unrecognized property
            } else {
              // throw runtime_error("Invalid property name");

            }
          }
        }

        // If we're parsing the animation
      } else {
        // If we meet ANIEND, it's over.
        if (line.find("ANIEND") == 0) {
          break;
        }

        if (direction == 0) {
          currentGani->aniFrames.push_back(AniFrame());
        }

        AniFrame &currentFrame = currentGani->aniFrames[currentGani->aniFrames.size() - 1];

        // 4 lines stuck together are to mean 4 directional
        // If a line is empty, a new frame starts
        if (line.isEmpty()) {
          direction = 0;
          continue;

        } else if (line.find("WAIT") == 0) {
          vector<CString> splitLine = line.tokenize(' ');
          currentFrame.wait += stoi(splitLine[1].text());

        } else if (line.find("PLAYSOUND") == 0) {
          vector<CString> splitLine = line.tokenize(' ');
          // Erase "PLAYSOUND"
          splitLine.erase(splitLine.begin());

          // x and y are the two last arguments
          double y = stod(splitLine.back().text());
          splitLine.pop_back();
          double x = stod(splitLine.back().text());
          splitLine.pop_back();

          // All that's left should be the filename
          string fileName = utils::concatenateSpacedFileName(splitLine);

          currentFrame.sounds.push_back(Sound(fileName, x, y));

        } else {
          AniDir *aniDir = new AniDir(static_cast<Directions>(direction));
          layer = 0;

          vector<CString> lineSprites = line.tokenize(',', true);
          for ( const CString& sprite : lineSprites) {
            vector<CString> info = sprite.tokenize(' ');

            aniDir->aniSprites.push_back(AniSprite(stoi(info[0].text()), stoi(info[1].text()), stoi(info[2].text()), layer));
            layer++;
          }

          currentFrame.aniDirs.push_back(*aniDir);
          direction++;
        }
      }
    }
    return *currentGani;
  }
}
