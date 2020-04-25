#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "utils.h"
#include "ganiInformation.h"
#include "ganiParser.h"
#include "save.h"

using namespace std;

int main() {
  ifstream file = utils::openFile("assets/yay.gani");

  vector<string> lines = utils::getGaniLines(file);

  file.close();

  GaniBuilding::GaniInformation currentAni;

  if (lines[0].find("GANI") == 0 || lines[0].find("SPRITE") == 0 ) {
    currentAni = GaniParsing::parse(lines);
  } else {
    throw runtime_error("File type not supported");
  }

  Saving::save(currentAni, "test", "bs");

  cout << "HAI";

  return 0;
}

