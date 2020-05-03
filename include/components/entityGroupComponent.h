//=================================
// include guard
#ifndef _entityGroupComponent_h_
#define _entityGroupComponent_h_

#include <vector>

#include "include/enums.h"
#include "include/components/basics.h"

#include "dependencies/entt/entity/registry.hpp"

namespace EntityGroupComponent{

  struct EntityList{
    std::vector<entt::entity> entities;
  };

  struct NewEntry{};

  struct ListId{};

  struct Scrollable{
    Size containerSize;

  };

  // Add to an entity group
  struct Gridded{
    // // Grids is a vector of how many entity per row/column there is (deleted)
    // -1 means "all the rest" or "all" (-1 in rows with 2 in columns would
    // separate all the entities in two columns)
    // std::vector<int> grids;
    int rows;
    int columns;
    ReadingOrder readingOrder;
    bool spacingIsFixed;
    Size fixedSpacing;
  };

  // Add to single components
  struct Padded {
    Size padding;
  };

  struct FollowResize{

  };

  struct 

}

#endif