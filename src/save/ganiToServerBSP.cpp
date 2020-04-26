
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/io/gzip_stream.h>

#include "src/components/ganiInformation.h"
#include "include/test.pb.h"
// #include "save.h"

using namespace std;
using namespace GaniBuilding;

namespace Saving {

  void ganiToServerBSP(cGaniInformation aniInfo, string fileName, string as){
    GaniInformation_SpriteDef *spriteDef = new GaniInformation_SpriteDef();

    spriteDef->set_index(0);
    spriteDef->set_image("bob");
    spriteDef->set_offx(-21);
    spriteDef->set_offy(32);
    spriteDef->set_width(1024);
    spriteDef->set_height(3);
    spriteDef->set_name("L'image de bobinot");
    spriteDef->set_defaultimage(GaniInformation_SpriteDef_DefaultImageType_BODY);
    

    // fstream output("bob.bsp", ios::out | ios::trunc | ios::binary);
    // spriteDef->SerializeToOstream(&output);

    auto uncompressedBytes = spriteDef->ByteSizeLong();

    std::unique_ptr<char[]> buffer(new char[uncompressedBytes]);
    google::protobuf::io::ArrayOutputStream aos(buffer.get(), (int) uncompressedBytes);
    google::protobuf::io::GzipOutputStream gos(&aos);

    if (spriteDef->SerializeToZeroCopyStream(&gos)){
      gos.Close();
 
      if (gos.ZlibErrorCode() > 0)
      {
        auto compressedBytes = aos.ByteCount();
        std::ofstream out("bob.bsp", std::ios::binary);
        out.write(buffer.get(), compressedBytes);
 
        std::cout << "Wrote compressed Protobuf message of size " << compressedBytes << " bytes ("
          << (100.0 * (uncompressedBytes - compressedBytes) / uncompressedBytes) << "% compression ratio): "
          << "bob.bsp" << std::endl;
      }
    }

  }

}
