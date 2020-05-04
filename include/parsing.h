//=================================
// include guard
#ifndef _parsing_h_
#define _parsing_h_

#include <vector>
#include <string>
#include <fstream>

#include "components/ganiInformation.h"

namespace Parsing{

  GaniBuilding::GaniInformation parse(std::vector<std::string> lines);

  GaniBuilding::GaniInformation parse(std::ifstream &file, std::string fileType);

  GaniBuilding::GaniInformation parseGani(std::vector<std::string> lines);

  GaniBuilding::GaniInformation parseServerBSP(std::ifstream &file);

}

#endif