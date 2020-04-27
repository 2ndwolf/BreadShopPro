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
#include <vector>
#include <stdexcept>
#include <CString.h>

using namespace std;

namespace utils {
  CString concatenateSpacedFileName(vector<CString> currentLine);
}
#endif
