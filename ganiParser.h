//=================================
// include guard
#ifndef _ganiParser_h_
#define _ganiParser_h_

#include "ganiInformation.h"

#include <vector>
#include <string>
#include <stdexcept>

using namespace std;
using namespace GaniBuilding;

namespace GaniParsing {
    GaniInformation parse(vector<string> lines);
}

#endif