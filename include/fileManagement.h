//=================================
// include guard
#ifndef _fileManagement_h_
#define _fileManagement_h_

#include "dependencies/entt/entity/registry.hpp"

#include "include/components/fileManagementComponent.h"

using namespace FileManagementComponent;

namespace CreateEntities{
  void create(entt::registry registry, FileManagementComponent::ioFile data);
}

#endif