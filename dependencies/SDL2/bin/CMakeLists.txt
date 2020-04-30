message("-- SDL2")
add_library(SDL2 libSDL2.dll.a)
set_target_properties(SDL2 PROPERTIES LINKER_LANGUAGE CXX)
message("-- SDL2-Image")
add_library(SDL2_image libSDL2_image.dll.a)
set_target_properties(SDL2_image PROPERTIES LINKER_LANGUAGE CXX)

