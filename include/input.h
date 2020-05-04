//=================================
// include guard
#ifndef _input_h_
#define _input_h_

#include <map>

namespace Input{

  void initKeyBinds();

  void updateMouse();

  int pollEvents();
  void updateInputStates(std::map<int, int> &inputStates);

  void updateSquare();

}

#endif