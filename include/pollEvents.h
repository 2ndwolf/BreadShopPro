//=================================
// include guard
#ifndef _pollEvents_h_
#define _pollEvents_h_

#include <map>

namespace Events {

  int pollEvents();
  void updateInputStates(std::map<int, int> &inputStates);

}
#endif