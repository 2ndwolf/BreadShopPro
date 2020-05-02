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
#include "include/keyActions.h"

using namespace std;
using namespace RenderComponent;

std::map<int, int> GameObjectComponent::KeyStates::keycodeStates;

int main() {

    Rendering::initRender();

    std::string fileName = "assets/gen_specialchest.gif";

    PbRender::createRenderable(fileName, 10, 10, 10, 10);
    PbRender::createRenderable(fileName, 20, 20, 10, 10);

    Window::close = 0;
    GameObjectComponent::KeyStates::keycodeStates.insert({0,0});

    // // annimation loop 
    while (!Window::close) { 

    //     // Events mangement 
        Input::updateKeyStates();
        Window::close = Events::pollEvents();
        Input::updateSquare();
  
        Rendering::loopRender();

    } 
  
    Rendering::killRender();

    return 0; 
  }



  // GaniInformation currentAni = Opening::open("assets/test.serverbsp");

  // Saving::save(currentAni, "test", "serverbsp");

//   return 0;
// }