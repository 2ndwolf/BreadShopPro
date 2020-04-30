
#include <vector>
#include <string>

#include "include/components/ganiInformation.h"


namespace Parsing {

  GaniBuilding::GaniInformation parse(std::vector<std::string> lines);

  GaniBuilding::GaniInformation parse(std::ifstream &file, std::string fileType);

}