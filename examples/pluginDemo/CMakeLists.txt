cmake_minimum_required(VERSION 3.23)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif ()

project(PluginDemo)

include_directories(../AndroidClass/include)
include_directories(../AndroidClass/ClassManager)
include_directories(../CommTools/share)
include_directories(../DisAsmEngine/include/capstone)

set(Plugin_SOURCES
        src/PluginExport.cpp
        src/CBizWorker.cpp
        src/BizJavaCls/com_honeybadger_nativelib_NativeLib1.cpp)


#include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(PluginDemo SHARED ${Plugin_SOURCES} )

target_link_libraries(PluginDemo PRIVATE AndroidClass CommTools)
