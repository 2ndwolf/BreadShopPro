//=================================
// include guard
#ifndef _saving_h_
#define _saving_h_

#include <string>

#include "include/components/ganiInformation.h"
#include "src/proto/gani_building.pb.h"



namespace Saving {

  void save(GaniBuilding::GaniInformation aniInfo, std::string fileName, std::string as);

  void ganiToBS(GaniBuilding::GaniInformation aniInfo, std::string fileName, std::string as);

  void ganiToServerBSP(GaniBuilding::GaniInformation object, std::string fileName, std::string as);

}

namespace ganiToServerBSP{
  void populate_SpriteDef(GaniBuilding::SpriteDef object, gani_building_sprite_def* pointer);
  void populate_Sound(GaniBuilding::Sound object, gani_building_sound* pointer);
  void populate_AniSprite(GaniBuilding::AniSprite object, gani_building_ani_sprite* pointer);
  void populate_AniDir(GaniBuilding::AniDir object, gani_building_ani_dir* pointer);
  void populate_AniFrame(GaniBuilding::AniFrame object, gani_building_ani_frame* pointer);
  void populate_AttachedSprite(GaniBuilding::AttachedSprite object, gani_building_attached_sprite* pointer);
  void populate_GaniInformation(GaniBuilding::GaniInformation object, gani_building_gani_information* pointer);
  void populate_AniSprite(std::vector<GaniBuilding::AniSprite> object, gani_building_ani_dir* pointer);
  void populate_AniDir(std::vector<GaniBuilding::AniDir> object, gani_building_ani_frame* pointer);
  void populate_Sound(std::vector<GaniBuilding::Sound> object, gani_building_ani_frame* pointer);
  void populate_SpriteDef(std::vector<GaniBuilding::SpriteDef> object, gani_building_gani_information* pointer);
  void populate_AniFrame(std::vector<GaniBuilding::AniFrame> object, gani_building_gani_information* pointer);
  void populate_Property(std::vector<GaniBuilding::Property> object, gani_building_gani_information* pointer);
  void populate_AttachedSprite(std::vector<GaniBuilding::AttachedSprite> object, gani_building_gani_information* pointer);
  void populate_defaultAttributes(std::vector<std::string> object, gani_building_gani_information* pointer);
  void populate_defaultParameters(std::vector<std::string> object, gani_building_gani_information* pointer);
}

#endif
