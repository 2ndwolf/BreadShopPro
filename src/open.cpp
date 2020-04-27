
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>         // std::locale, std::tolower


#include "components/ganiInformation.h"
#include "include/stringUtils.h"
#include "include/parse.h"
// #include "../include/ganiOpener.h"

using namespace std;
using namespace GaniBuilding;

namespace Opening {

  cGaniInformation open(string fileName){
    ifstream file;
    cGaniInformation ganiInfo;
    vector<string> splitFileName = utils::split(fileName, '.');

    string fileExtension;

    for(char c : splitFileName[1]){
      fileExtension += tolower(c);
    }

    file.open(fileName);

    if (file.is_open()) {
      
      // If tokenizedFileName[1].to_lower == "gani"
      if(fileExtension == "gani" || fileExtension == "bs"){
        vector<string> lines = utils::getTextLines(file);
        ganiInfo = Parsing::parse(lines);
      } else if(fileExtension == "serverbsp"){

      }

      file.close();

    } else {
      throw runtime_error("File could not be opened");
    }

    return ganiInfo;
  }


}