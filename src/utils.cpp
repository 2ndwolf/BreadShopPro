#include "utils.h"

using namespace std;

namespace utils {
  CString concatenateSpacedFileName(vector<CString> currentLine) {
    CString fileName;
    for (int i = 0; i < currentLine.size(); i++) {
      if (i > 0) {
        fileName << " ";
      }
      fileName << currentLine[i];
    }
    return fileName;
  }
}
