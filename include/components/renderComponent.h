//=================================
// include guard
#ifndef _renderComponent_h_
#define _renderComponent_h_

#include <vector>
#include <map>

#include <dependencies/SDL2/SDL.h> 


namespace RenderComponent {

  class Window{
    public:
    static int close;
  };

  class Render{
    public:
    static SDL_Window* sdlWindow;
    static SDL_Renderer* sdlRenderer;
  };

  class Renderable{
    public:
    SDL_Texture* sdlTexture;
    SDL_Rect sdlRect;
    SDL_Rect srcRect;
    int layer;
    bool hidden;
  };


  class RenderableList{
    public:
    static std::vector<Renderable*> renderables;
  };

  class SurfaceList{
    public:
    static std::map<std::string, SDL_Surface*> surfaces;
  };


  // Realistic components
  struct EntityRenderables{
    std::vector<Renderable*> renderables;
  };

}

#endif