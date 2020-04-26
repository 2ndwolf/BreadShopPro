//=================================
// include guard
#ifndef _ganiToServerBSP_h_
#define _ganiToServerBSP_h_

#include <string>

#include "../src/components/ganiInformation.h"

namespace Saving {

  void ganiToServerBSP(GaniBuilding::cGaniInformation aniInfo, std::string fileName, std::string as);

}

#endif