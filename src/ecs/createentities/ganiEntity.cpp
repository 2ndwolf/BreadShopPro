#include "dependencies/entt/entity/registry.hpp"

#include "include/components/gameObject.h"
#include "include/components/ganiInformation.h"
#include "include/components/renderComponent.h"
#include "include/components/basics.h"
#include "include/renderables.h"

#include "include/open.h"

using namespace RenderComponent;

namespace CreateEntities{

  // Create Gani
  void create(entt::registry registry, GaniBuilding::GaniInformation mainClass){   
    auto entity = registry.create();
    EntityRenderables &ER = registry.emplace<EntityRenderables>(entity);
    std::string fileName = "assets/gen_specialchest.gif";
    PbRender::createRenderable(fileName);

    // Call delete (unless reuse == true)?
  }
}
