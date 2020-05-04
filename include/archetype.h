//=================================
// include guard
#ifndef _archetype_h_
#define _archetype_h_

#include "dependencies/entt/entity/registry.hpp"

#include "components/ganiInformation.h"
#include "include/components/customize.h"


namespace Archetype{

  // Create Customization entity
  entt::entity create(entt::registry& registry, entt::entity& entityPart, CustomizeComponent::Custom mainClass);
  entt::entity create(entt::registry& registry, entt::entity& entityPart, GaniBuilding::GaniInformation mainClass);
  entt::entity create(entt::registry& registry, entt::entity& entityPart, GaniBuilding::SpriteDef data);

}

#endif
