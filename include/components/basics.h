//=================================
// include guard
#ifndef _basics_h_
#define _basics_h_

#include <map>
#include <string>

struct Size{
  int width, height;
};

struct Position{
  int x, y, screenX, screenY;
};

struct Velocity{
  double dx, dy;
};

// typedef std::map<std::string, std::string> Name_File;

#endif