#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "utils.h"
#include "ganiInformation.h"
#include "ganiParser.h"

using namespace std;

int main() {
  ifstream file = utils::openFile("walk.gani");

  vector<string> lines = utils::getGaniLines(file);

  file.close();

  GaniBuilding::GaniInformation currentGani;

  if (lines[0].find("GANI") == 0) {
    currentGani = GaniParsing::parse(lines);
  } else {
    throw runtime_error("File type not supported");
  }

  cout << "HAI";

  return 0;
}

