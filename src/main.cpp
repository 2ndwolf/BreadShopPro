#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/io/gzip_stream.h>

#define SDL_MAIN_HANDLED

#include "include/initRender.h"
#include "include/killRender.h"
#include "include/loopRender.h"

#include "include/renderables.h"

#include "include/components/renderComponent.h"
#include "include/components/gameObject.h"
#include "include/components/ganiInformation.h"

#include "include/pollEvents.h"
#include "include/updateSquare.h"

#include "include/mouseActions.h"

#include "include/open.h"
#include "include/save.h"

#include "dependencies/entt/entity/registry.hpp"

#include "include/fileManagement.h"
#include "include/ganiEntity.h"
#include "include/initKeyBinds.h"

using namespace std;
using namespace RenderComponent;


int main() {

  //   GaniBuilding::GaniInformation currentAni = Opening::open("assets/yay.gani");

  // Saving::save(currentAni, "test", "bs");
  entt::registry registry;
  std::uint64_t dt = 16;

  Rendering::initRender();
  Input::initKeyBinds();

  // Entities::createFileManagement(registry);
  // Entities::createGaniEntity(registry);

  std::string fileName = "assets/gen_specialchest.gif";
  PbRender::createRenderable(fileName);

  Window::close = 0;

  while (!Window::close) { 

    Window::close = Events::pollEvents();
    Input::updateSquare();
    Input::updateMouse();
    Rendering::loopRender();

  } 

  Rendering::killRender();

  return 0; 
}



  // GaniInformation currentAni = Opening::open("assets/test.serverbsp");

  // Saving::save(currentAni, "test", "serverbsp");

//   return 0;
// }