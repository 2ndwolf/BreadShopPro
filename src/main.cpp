#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/io/gzip_stream.h>

#define SDL_MAIN_HANDLED

#include "dependencies/entt/entity/registry.hpp"

#include "components/gameObject.h"
#include "components/ganiInformation.h"
#include "components/renderComponent.h"
#include "components/fileManagementComponent.h"

#include "input.h"
#include "saving.h"
#include "opening.h"
#include "pbrender.h"
#include "rendering.h"
#include "archetype.h"





using namespace std;
using namespace RenderComponent;
using namespace FileManagementComponent;

std::string FileInfo::name;
std::string FileInfo::path;

int main() {

  //   GaniBuilding::GaniInformation currentAni = Opening::open("assets/yay.gani");

  // Saving::save(currentAni, "test", "bs");
  entt::registry registry;
  std::uint64_t dt = 16;

  Rendering::initRender();
  Input::initKeyBinds();

  // Entities::createFileManagement(registry);
  // Entities::createGaniEntity(registry);

  FileInfo::path = "assets/";
  FileInfo::name = "yay.gani";

  std::string fileName = "assets/gen_specialchest.gif";
  PbRender::createRenderable(fileName);

  Window::close = 0;

  while (!Window::close) { 

    Window::close = Input::pollEvents();
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