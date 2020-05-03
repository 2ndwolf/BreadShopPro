#include "dependencies/entt/entity/registry.hpp"

#include "include/components/gameObject.h"
#include "include/components/ganiInformation.h"
#include "include/components/renderComponent.h"
#include "include/components/basics.h"
#include "include/renderables.h"

#include "include/open.h"

#include "include/components/customize.h"

using namespace RenderComponent;

namespace CreateEntities{

  // Create Customization entity
  void create(entt::registry registry, CustomizeComponent::Custom mainClass){   
    auto entity = registry.create();
    CustomizeComponent::Custom &custom = registry.emplace<CustomizeComponent::Custom>(entity);


  }
}