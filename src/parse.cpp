
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include "components/ganiInformation.h"
#include "include/ganiParser.h"

using namespace std;
using namespace GaniBuilding;

namespace Parsing {

  cGaniInformation parse(vector<string> lines){

    cGaniInformation currentAni;

    if (lines[0].find("GANI") == 0 || lines[0].find("SPRITE") == 0 ) {
      currentAni = Parsing::parseGani(lines);
    } else {
      throw runtime_error("File type not supported");
    }

    return currentAni;
  }

  

}