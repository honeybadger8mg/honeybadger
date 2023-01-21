cmake_minimum_required(VERSION 3.23)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif ()

project(PluginDemo)

include_directories(include)
include_directories(hb_headers/AndroidClass/include)
include_directories(hb_headers/CommTools/include)



if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    link_directories(hb_libs/debug)
else ()
    link_directories(hb_libs/release)
endif ()


set(Plugin_SOURCES
        src/PluginExport.cpp
        src/CBizWorker.cpp
        src/BizJavaCls/com_honeybadger_nativelib_NativeLib1.cpp)


#include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(PluginDemo SHARED ${Plugin_SOURCES} )

target_link_libraries(PluginDemo PRIVATE AndroidClass CommTools)
