
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include "components/ganiInformation.h"
#include "include/ganiParser.h"

using namespace std;
using namespace GaniBuilding;

namespace Parsing {

  GaniInformation parse(vector<string> lines){

    GaniInformation currentAni;

    if (lines[0].find("GANI") == 0 || lines[0].find("SPRITE") == 0 ) {
      currentAni = Parsing::parseGani(lines);
    } else {
      throw runtime_error("File type not supported");
    }

    return currentAni;
  }

  GaniInformation parse2(ifstream file, string fileType){

    GaniInformation currentAni;

    // currentAni = Parsing::parseServerBSP(file);

    return currentAni;
  }

}