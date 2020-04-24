#include <iostream>
#include <vector>
#include <string>

#include "ganiInformation.h"
#include "utils.h"
#include "enums.h"
#include "ganiParser.h"

using namespace std;
using namespace GaniBuilding;

namespace GaniParsing {
  GaniInformation parse(vector<string> lines) {
    bool isAni = false;
    int layer, direction;

    GaniInformation *currentGani = new GaniInformation();

    for (string &line : lines) {
      // line.erase(remove(line.begin(), line.end(), '\n'), line.end());
      // line.erase(remove(line.begin(), line.end(), '\r'), line.end());

      // does nothing...
      if (line.empty()) {
        continue;
      }

      if (!isAni) {
        vector<string> splitLine = utils::split(line, ' ');

        string firstArgument = splitLine[0];


        if(firstArgument == "SPRITE"){
          cout << splitLine[1];
          string spriteName;
          for (int i = 7; i < splitLine.size(); i++) {
            // Add spaces
            spriteName += splitLine[i];
          }
          currentGani->spriteDefs.push_back(
                  SpriteDef(stoi(splitLine[1]), splitLine[2], stoi(splitLine[3]), stoi(splitLine[4]),
                            stoi(splitLine[5]), stoi(splitLine[6]), spriteName));
        } else if (firstArgument == "ATTACHSPRITE") {
          currentGani->attachedSprites.push_back(
                  AttachedSprite(stoi(splitLine[1]), stoi(splitLine[2]), stoi(splitLine[3]), stoi(splitLine[4])));
        } else if (firstArgument == "ANI") {
          isAni = true;
          direction, layer = 0;
          continue;

          // If not ANI or SPRITE and isAni is false, then it is a Property
        } else {
          if(firstArgument.find("LOOP") == 0){
            currentGani->properties.push_back(Property::LOOP);
            cout << "HALLO";
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

              }

              // If it's neither a SPRITE, property or DEFAULT,
              // and is not part of the animation, then it is an
              // unrecognized property

              // There is also an ATTACHSPRITE property, dunno what it does
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
        if (line == "") {
          direction = 0;
          continue;

        } else if (line.find("WAIT") == 0) {
          vector<string> splitLine = utils::split(line, ' ');
          currentFrame.wait += stoi(splitLine[1]);

        } else if (line.find("PLAYSOUND") == 0) {
          vector<string> splitLine = utils::split(line, ' ');
          // Erase "PLAYSOUND"
          splitLine.erase(splitLine.begin());

          // x and y are the two last arguments
          int y = stoi(splitLine.back());
          splitLine.pop_back();
          int x = stoi(splitLine.back());
          splitLine.pop_back();

          // All that's left should be the filename
          string fileName;
          for (string &namePart : splitLine) {
            fileName += namePart;
          }

          currentFrame.sounds.push_back(Sound(fileName, x, y));

        } else {
          AniDir *aniDir = new AniDir(static_cast<Directions>(direction));
          layer = 0;

          vector<string> lineSprites = utils::split(line, ',');
          for (string &sprite : lineSprites) {
            vector<string> info = utils::split(sprite, ' ');

            aniDir->aniSprites.push_back(AniSprite(stoi(info[0]), stoi(info[1]), stoi(info[2]), layer));
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
