message("-- Google protocol buffers")
add_library(Protobufs libprotobuf.dll)
set_target_properties(Protobufs PROPERTIES LINKER_LANGUAGE CXX)