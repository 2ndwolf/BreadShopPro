#include "dependencies/entt/entity/registry.hpp"

#include "components/gameObject.h"
#include "components/ganiInformation.h"
#include "components/renderComponent.h"
#include "components/basics.h"
#include "components/customize.h"

#include "rendering.h"
#include "opening.h"

#include "archetype.h"

using namespace RenderComponent;

namespace Archetype{

  // Create Customization entity
  void create(entt::registry registry, entt::entity& entityPart, CustomizeComponent::Custom mainClass){   
    auto entity = registry.create();
    CustomizeComponent::Custom &custom = registry.emplace<CustomizeComponent::Custom>(entity);


  }
}