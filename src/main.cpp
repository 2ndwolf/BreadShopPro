#include <iostream>
#include <stdexcept>
#include <CString.h>

#include "ganiInformation.h"
#include "ganiParser.h"
#include "save.h"

using namespace std;

int main() {
  CString lines;
  lines.load("assets/yay.gani");

  GaniBuilding::GaniInformation currentAni;

  if (lines.find("GANI") == 0 || lines.find("SPRITE") == 0 ) {
    currentAni = GaniParsing::parse(lines);
  } else {
    throw runtime_error("File type not supported");
  }

  Saving::save(currentAni, "test", "bs");

  cout << "HAI";

  return 0;
}

