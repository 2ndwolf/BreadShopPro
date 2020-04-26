//=================================
// include guard
#ifndef _ganiParser_h_
#define _ganiParser_h_

#include <vector>
#include <string>
#include <stdexcept>

#include "src/components/ganiInformation.h"


namespace GaniParsing {
  GaniBuilding::cGaniInformation parse(std::vector<std::string> lines);
}

#endif
