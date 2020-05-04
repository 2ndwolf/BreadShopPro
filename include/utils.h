//=================================
// include guard
#ifndef _utils_h_
#define _utils_h_

//=================================
// forward declared dependencies
// class Foo;
// class Bar;
// forward declare what you can
// then you can go: Foo* foo;
// since it only uses a pointer you
// can forward declare

//=================================
// included dependencies
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

namespace utils {
  vector<string> getTextLines(ifstream &file);

  vector<string> split(const string &text, char sep);

  string concatenateSpacedFileName(vector<string> &currentLine);
}
#endif
