cmake_minimum_required(VERSION 3.16)
project(BreadShopPro)

string(TOLOWER ${PROJECT_NAME} EXECUTABLE)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(${EXECUTABLE}
        enums.h
        ganiParser.cpp
        ganiParser.h
        ganiInformation.h
        saveBSP.cpp
        saveBSP.h
        main.cpp
        utils.cpp
        utils.h)
