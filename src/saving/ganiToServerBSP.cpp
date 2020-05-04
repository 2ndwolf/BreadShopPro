#include <fstream>
#include <cstring>
#include <string>
#include <vector>

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/gzip_stream.h>

#include "components/ganiInformation.h"

#include "src/proto/gani_building.pb.h"

#include "saving.h"

namespace Saving {
  void ganiToServerBSP(GaniBuilding::GaniInformation object, std::string fileName, std::string as){
    gani_building_gani_information *pointer = new gani_building_gani_information;
    ganiToServerBSP::populate_GaniInformation(object, pointer);

    std::cout << pointer->default_head();

     auto uncompressedBytes = (*pointer).ByteSizeLong();
     std::cout << uncompressedBytes << std::endl;

     std::unique_ptr<char[]> buffer(new char[uncompressedBytes]);
     google::protobuf::io::ArrayOutputStream aos(buffer.get(), (int) uncompressedBytes);
     google::protobuf::io::GzipOutputStream gos(&aos);

     if (pointer->SerializeToZeroCopyStream(&gos)){
       gos.Close();

       if (gos.ZlibErrorCode() > 0)
       {
         auto compressedBytes = aos.ByteCount();
         std::ofstream out(fileName + "." + as, std::ios::binary);
         out.write(buffer.get(), compressedBytes);

         std::cout << "Wrote compressed Protobuf message of size " << compressedBytes << " bytes ("
           << (100.0 * (uncompressedBytes - compressedBytes) / uncompressedBytes) << "% compression ratio): "
           << fileName + "." + as << std::endl;
       }
    }
}
}

namespace ganiToServerBSP{

void populate_SpriteDef(GaniBuilding::SpriteDef object, gani_building_sprite_def* pointer){
  pointer->set_index(object.index);
  pointer->set_image(object.image);
  pointer->set_off_x(object.offX);
  pointer->set_off_y(object.offY);
  pointer->set_width(object.width);
  pointer->set_height(object.height);
  pointer->set_name(object.name);
  pointer->set_default_image(
    static_cast<gani_building_default_image_type>(object.defaultImage));
}

void populate_Sound(GaniBuilding::Sound object, gani_building_sound* pointer){
  pointer->set_file_name(object.fileName);
  pointer->set_x(object.x);
  pointer->set_y(object.y);
}

void populate_AniSprite(GaniBuilding::AniSprite object, gani_building_ani_sprite* pointer){
  pointer->set_sprite_index(object.spriteIndex);
  pointer->set_x(object.x);
  pointer->set_y(object.y);
  pointer->set_layer(object.layer);
}

void populate_AniDir(GaniBuilding::AniDir object, gani_building_ani_dir* pointer){
  pointer->set_direction(
    static_cast<gani_building_directions>(object.direction));
  populate_AniSprite(object.aniSprites, pointer);
}

void populate_AniFrame(GaniBuilding::AniFrame object, gani_building_ani_frame* pointer){
  populate_AniDir(object.aniDirs, pointer);
  pointer->set_wait(object.wait);
  populate_Sound(object.sounds, pointer);
}

void populate_AttachedSprite(GaniBuilding::AttachedSprite object, gani_building_attached_sprite* pointer){
  pointer->set_sprite_a(object.spriteA);
  pointer->set_sprite_b(object.spriteB);
  pointer->set_rel_x(object.relX);
  pointer->set_rel_y(object.relY);
}

void populate_GaniInformation(GaniBuilding::GaniInformation object, gani_building_gani_information* pointer){
  populate_SpriteDef(object.spriteDefs, pointer);
  populate_AniFrame(object.aniFrames, pointer);
  populate_Property(object.properties, pointer);
  populate_AttachedSprite(object.attachedSprites, pointer);
  populate_defaultAttributes(object.defaultAttributes, pointer);
  populate_defaultParameters(object.defaultParameters, pointer);
  pointer->set_default_head(object.defaultHead);
  pointer->set_default_body(object.defaultBody);
  pointer->set_next_gani(object.nextGani);
}

void populate_AniSprite(std::vector<GaniBuilding::AniSprite> object, gani_building_ani_dir* pointer){
  for(int i = 0; i < object.size(); i++){
    populate_AniSprite(object[i], pointer->add_ani_sprites());
  }
}

void populate_AniDir(std::vector<GaniBuilding::AniDir> object, gani_building_ani_frame* pointer){
  for(int i = 0; i < object.size(); i++){
    populate_AniDir(object[i], pointer->add_ani_dirs());
  }
}

void populate_Sound(std::vector<GaniBuilding::Sound> object, gani_building_ani_frame* pointer){
  for(int i = 0; i < object.size(); i++){
    populate_Sound(object[i], pointer->add_sounds());
  }
}

void populate_SpriteDef(std::vector<GaniBuilding::SpriteDef> object, gani_building_gani_information* pointer){
  for(int i = 0; i < object.size(); i++){
    populate_SpriteDef(object[i], pointer->add_sprite_defs());
  }
}

void populate_AniFrame(std::vector<GaniBuilding::AniFrame> object, gani_building_gani_information* pointer){
  for(int i = 0; i < object.size(); i++){
    populate_AniFrame(object[i], pointer->add_ani_frames());
  }
}

// Populates an enum 
void populate_Property(std::vector<GaniBuilding::Property> object, gani_building_gani_information* pointer){
  for(int i = 0; i < object.size() - 1; i++){
    pointer->add_properties(static_cast<gani_building_property>(object[i]));
  }
}

void populate_AttachedSprite(std::vector<GaniBuilding::AttachedSprite> object, gani_building_gani_information* pointer){
  for(int i = 0; i < object.size(); i++){
    populate_AttachedSprite(object[i], pointer->add_attached_sprites());
  }
}

void populate_defaultAttributes(std::vector<std::string> object, gani_building_gani_information* pointer){
  for(int i = 0; i < object.size(); i++){
    pointer->add_default_attributes(object[i]);
  }
}

void populate_defaultParameters(std::vector<std::string> object, gani_building_gani_information* pointer){
  for(int i = 0; i < object.size(); i++){
    pointer->add_default_parameters(object[i]);
  }
}

}
