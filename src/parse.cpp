
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include "include/components/ganiInformation.h"
#include "include/parse.h"
#include "include/ganiParser.h"
#include "include/serverBSPParser.h"

using namespace std;
using namespace GaniBuilding;

namespace Parsing {

  GaniInformation parse(vector<std::string> lines){

    GaniInformation currentAni;

    if (lines[0].find("GANI") == 0 || lines[0].find("SPRITE") == 0 ) {
      currentAni = Parsing::parseGani(lines);
    } else {
      throw runtime_error("File type not supported");
    }

    return currentAni;
  }

  GaniBuilding::GaniInformation parse(std::ifstream &file, std::string fileType){

    GaniInformation currentAni;

    currentAni = Parsing::parseServerBSP(file);

    return currentAni;
  }

}