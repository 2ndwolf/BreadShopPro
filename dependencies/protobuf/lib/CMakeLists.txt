message("-- Google protocol buffers")
add_library(protobufs libprotobuf.a)
set_target_properties(protobufs PROPERTIES LINKER_LANGUAGE CXX)
