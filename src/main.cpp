#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/io/gzip_stream.h>

#include "components/ganiInformation.h"
#include "include/ganiParser.h"
#include "include/stringUtils.h"
#include "include/save.h"
#include "include/parse.h"
#include "include/open.h"

using namespace std;
using namespace GaniBuilding;

int main() {

  // std::string protobufPath("bob.bsp");
  // std::string bitmapPath("Mona_Lisa_decompressed.bmp");
  // std::ifstream in(protobufPath, std::ios::binary);


  GaniInformation currentAni = Opening::open("assets/yay.gani");

  Saving::save(currentAni, "test", "serverbsp");

  return 0;
}