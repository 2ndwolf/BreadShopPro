
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include "components/ganiInformation.h"
#include "include/ganiToBS.h"
#include "include/ganiToServerBSP.h"
#include "include/save.h"

using namespace std;
using namespace GaniBuilding;

namespace Saving {

  void save(cGaniInformation aniInfo, string fileName, string as){
    if(as == "bs"){
      ganiToBS(aniInfo, fileName, as);
    } else if(as == "serverbsp"){
      ganiToServerBSP(aniInfo, fileName, as);
    }
  }

}