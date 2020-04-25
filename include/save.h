//=================================
// include guard
#ifndef _save_h_
#define _save_h_
#include <CString.h>

#include "ganiInformation.h"

using namespace std;
using namespace GaniBuilding;

namespace Saving {

  void save(GaniInformation aniInfo, const string& fileName, const string& as);

}
#endif
