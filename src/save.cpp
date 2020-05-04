
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include "components/ganiInformation.h"

#include "saving.h"

using namespace std;
using namespace GaniBuilding;

namespace Saving {

  void save(GaniInformation aniInfo, string fileName, string as){
    if(as == "bs"){
      ganiToBS(aniInfo, fileName, as);
    } else if(as == "serverbsp"){
      ganiToServerBSP(aniInfo, fileName, as);
    }
  }

}