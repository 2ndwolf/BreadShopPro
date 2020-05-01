#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/io/gzip_stream.h>

#define SDL_MAIN_HANDLED

#include <dependencies/SDL2/SDL.h> 
#include <dependencies/SDL2/SDL_image.h> 
#include <dependencies/SDL2/SDL_timer.h>

#include "include/components/ganiInformation.h"
#include "include/ganiParser.h"
#include "include/stringUtils.h"
#include "include/save.h"
#include "include/parse.h"
#include "include/open.h"
#include "include/constants.h"

#include "include/initRender.h"
#include "include/killRender.h"
#include "include/loopRender.h"

#include "include/renderables.h"

#include "include/components/renderComponent.h"

#include "include/mouseInput.h"

using namespace std;
using namespace GaniBuilding;
using namespace RenderComponent;

int main() {

    Rendering::initRender();

    std::string fileName = "assets/gen_specialchest.gif";
    std::cout << "BOBOBOBOBOB";

    PbRender::createBlittedRenderable(fileName, fileName, 10, 10, 10, 10);

    Window::close = 0;

    // // annimation loop 
    while (!Window::close) { 

    //     // Events mangement 
        Window::close = Input::mouseInput();
  
        Rendering::loopRender();

    } 
  
    Rendering::killRender();

    return 0; 
  }



  // GaniInformation currentAni = Opening::open("assets/test.serverbsp");

  // Saving::save(currentAni, "test", "serverbsp");

//   return 0;
// }