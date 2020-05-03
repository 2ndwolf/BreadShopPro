#include "dependencies/entt/entity/registry.hpp"

#include "include/components/fileManagementComponent.h"

#include "include/open.h"

using namespace FileManagementComponent;

namespace CreateEntities{
  
  void create(entt::registry registry, FileManagementComponent::ioFile data){
      auto entity = registry.create();
      registry.emplace<ioFile>(entity);


  }
}