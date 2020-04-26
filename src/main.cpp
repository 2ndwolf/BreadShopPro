#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/io/gzip_stream.h>

#include "components/ganiInformation.h"
#include "include/ganiParser.h"
#include "include/utils.h"
#include "include/save.h"
#include "include/test.pb.h"

using namespace std;

int main() {

  std::string protobufPath("bob.bsp");
  std::string bitmapPath("Mona_Lisa_decompressed.bmp");
  std::ifstream in(protobufPath, std::ios::binary);

  return 0;
}

  // ifstream file = utils::openFile("assets/yay.gani");

  // vector<string> lines = utils::getGaniLines(file);

  // file.close();

  // GaniBuilding::cGaniInformation currentAni;

  // if (lines[0].find("GANI") == 0 || lines[0].find("SPRITE") == 0 ) {
  //   currentAni = GaniParsing::parse(lines);
  // } else {
  //   throw runtime_error("File type not supported");
  // }

  // Saving::save(currentAni, "test", "bs");
//   return 0;
// }


