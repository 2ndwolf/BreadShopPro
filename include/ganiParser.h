//=================================
// include guard
#ifndef _ganiParser_h_
#define _ganiParser_h_

#include <vector>
#include <string>
#include <stdexcept>

#include "include/components/ganiInformation.h"


namespace Parsing {
  GaniBuilding::GaniInformation parseGani(std::vector<std::string> lines);
}

#endif
