//=================================
// include guard
#ifndef _renderables_h_
#define _renderables_h_

#include <string>

#include "include/components/renderComponent.h"

namespace PbRender{

  RenderComponent::Renderable createRenderable(std::string &fileName, int offX = 0, int offY = 0, int width = 0, int height = 0);
  
}

#endif