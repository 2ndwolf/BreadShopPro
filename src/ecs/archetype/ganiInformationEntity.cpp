#include "dependencies/entt/entity/registry.hpp"

#include "components/gameObject.h"
#include "components/ganiInformation.h"
#include "components/renderComponent.h"
#include "components/basics.h"

#include "rendering.h"
#include "opening.h"

#include "archetype.h"

using namespace RenderComponent;

namespace Archetype{

  // Create Gani
  void create(entt::registry& registry, entt::entity& entity, GaniBuilding::GaniInformation mainClass){   
    // auto entity = registry.create();
    // EntityRenderables &ER = registry.emplace<EntityRenderables>(entity);
    // std::string fileName = "assets/gen_specialchest.gif";
    // ER.renderables.push_back(&(PbRender::createRenderable(fileName)));

    GaniBuilding::GaniInformation &GaniInformation = registry.emplace<GaniBuilding::GaniInformation>(entity);
    GaniInformation.spriteDefs = mainClass.spriteDefs;
    GaniInformation.aniFrames = mainClass.aniFrames;
    GaniInformation.properties = mainClass.properties;
    GaniInformation.attachedSprites = mainClass.attachedSprites;
    GaniInformation.defaultAttributes = mainClass.defaultAttributes;
    GaniInformation.defaultParameters = mainClass.defaultParameters;
    GaniInformation.defaultHead = mainClass.defaultHead;
    GaniInformation.defaultBody = mainClass.defaultBody;
    GaniInformation.nextGani = mainClass.nextGani;
    // Call delete (unless reuse == true)?
  }
}
