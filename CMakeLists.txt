cmake_minimum_required(VERSION 3.16)
project(BreadShopPro)

string(TOLOWER ${PROJECT_NAME} EXECUTABLE)

set(CMAKE_CXX_STANDARD 17)

include_directories(
		${PROJECT_SOURCE_DIR}/include
                .
)

add_subdirectory(./dependencies/protobuf/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}../bin)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB NESTEDSOURCES ${PROJECT_SOURCE_DIR}/src/*/*.cpp)
file(GLOB COMPONENTS ${PROJECT_SOURCE_DIR}/src/components/*.h)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB PROTOH ${PROJECT_SOURCE_DIR}/include/*.pb.h)
file(GLOB PROTO ${PROJECT_SOURCE_DIR}/src/proto/*.cc)

add_executable(${EXECUTABLE} ${PROTOH} ${SOURCES} ${NESTEDSOURCES} ${COMPONENTS} ${HEADERS} ${PROTO})

add_dependencies(${EXECUTABLE} protobufs)

target_link_libraries(${EXECUTABLE} protobufs)
