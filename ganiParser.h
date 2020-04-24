//=================================
// include guard
#ifndef _ganiParser_h_
#define _ganiParser_h_

#include <vector>
#include <string>
#include <stdexcept>

#include "ganiInformation.h"

using namespace std;
using namespace GaniBuilding;

namespace GaniParsing {
  GaniInformation parse(vector<string> lines);
}

#endif
