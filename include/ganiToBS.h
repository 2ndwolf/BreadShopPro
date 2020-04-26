//=================================
// include guard
#ifndef _ganiToBS_h_
#define _ganiToBS_h_

#include <string>

#include "src/components/ganiInformation.h"

namespace Saving {

  void ganiToBS(GaniBuilding::cGaniInformation aniInfo, std::string fileName, std::string as);

}

#endif