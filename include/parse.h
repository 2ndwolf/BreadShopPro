
#include <vector>
#include <string>

#include "src/components/ganiInformation.h"


namespace Parsing {

  GaniBuilding::GaniInformation parse(std::vector<std::string> lines);

  GaniBuilding::GaniInformation parse2(ifstream file, string fileType);

}