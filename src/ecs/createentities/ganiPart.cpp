#include "dependencies/entt/entity/registry.hpp"

#include "include/components/gameObject.h"
#include "include/components/ganiInformation.h"

#include "include/open.h"


namespace CreateEntities{

  // A mouse interactive, selectable, movable with keyboard arrows
  // piece of spritesheet
  void create(entt::registry& registry, GaniBuilding::SpriteDef data){
      auto entity = registry.create();
      // EntityRenderables &ER = registry.emplace<EntityRenderables>(entity);
      
  }
}
