//=================================
// include guard
#ifndef _fileManagementComponent_h_
#define _fileManagementComponent_h_

#include <string>

#include "include/enums.h"

namespace FileManagementComponent{
  struct ioFile{
    std::string name;
    std::string path;
    FileAction fileAction;
  };

}

#endif