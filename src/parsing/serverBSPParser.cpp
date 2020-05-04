#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/io/gzip_stream.h>

#include "src/proto/gani_building.pb.h"
#include "components/ganiInformation.h"

#include "parsing.h"

using namespace std;

namespace Parsing {
  GaniBuilding::GaniInformation parseServerBSP(ifstream &file) {
    // std::string protobufPath("Mona_Lisa.pbz");
    // std::string bitmapPath("Mona_Lisa_decompressed.bmp");
    // std::ifstream in(protobufPath, std::ios::binary);
    GaniBuilding::GaniInformation currentAni;

    if (file)
    {

      file.unsetf(std::ios::skipws);
      file.seekg(0, std::ios::end);
      std::cout << "Read file with " << file.tellg() << " bytes" << std::endl;
      file.seekg(0, std::ios::beg);

      google::protobuf::io::IstreamInputStream iss(&file);
      google::protobuf::io::GzipInputStream gis(&iss);
      gani_building::gani_information blob;

      if (blob.ParseFromZeroCopyStream(&gis) && gis.ZlibErrorCode() > 0)
      {
        std::cout << blob.default_head();
      } else {
        std::cout << "error";
      }
    }

    return currentAni;
  }
}