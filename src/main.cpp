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

#include "include/pollEvents.h"
#include "include/updateSquare.h"

#include "include/mouseActions.h"


using namespace std;
using namespace RenderComponent;



int main() {

    Rendering::initRender();

    std::string fileName = "assets/gen_specialchest.gif";

    PbRender::createRenderable(fileName);

    Window::close = 0;

    while (!Window::close) { 

        // Events mangement 

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