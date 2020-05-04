//=================================
// include guard
#ifndef _pbRender_h_
#define _pbRender_h_

#include <string>

#include "include/components/renderComponent.h"

namespace PbRender{

  RenderComponent::Renderable createRenderable(std::string &fileName, int offX = 0, int offY = 0, int width = 0, int height = 0);
  
}

#endif