//=================================
// include guard
#ifndef _save_h_
#define _save_h_

#include <string>

#include "src/components/ganiInformation.h"


namespace Saving {

  void save(GaniBuilding::cGaniInformation aniInfo, std::string fileName, std::string as);

}
#endif
