//=================================
// include guard
#ifndef __utils_included__
#define __utils_included__

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
  vector<string> getGaniLines(ifstream &file);

  ifstream openFile(string fileName);

  vector<string> split(const string &text, char sep);

  string concatenateSpacedFileName(vector<CString> currentLine);
}
#endif
