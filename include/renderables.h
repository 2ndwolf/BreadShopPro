//=================================
// include guard
#ifndef _renderables_h_
#define _renderables_h_

#include <string>

#include "include/components/renderComponent.h"

namespace PbRender{

  RenderComponent::Renderable createRenderable(std::string &fileName);

  RenderComponent::Renderable createBlittedRenderable(std::string &fileName, std::string &blitName, int offX, int offY, int width, int height);

}

#endif