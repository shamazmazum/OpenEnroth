cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(BIN_OPENENROTH_SOURCES
        OpenEnroth.cpp
        OpenEnrothOptions.cpp)

set(BIN_OPENENROTH_HEADERS
        OpenEnrothOptions.h)

if(BUILD_PLATFORM STREQUAL "android")
    add_library(main SHARED)
    target_sources(main PUBLIC ${BIN_OPENENROTH_HEADERS} ${BIN_OPENENROTH_SOURCES})
    target_check_style(main)
    target_link_libraries(main PUBLIC application library_cli library_platform_main)
    target_link_options(main PRIVATE "-Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/libmain.map")
else()
    add_executable(OpenEnroth MACOSX_BUNDLE)
    target_sources(OpenEnroth PUBLIC ${BIN_OPENENROTH_HEADERS} ${BIN_OPENENROTH_SOURCES})
    target_check_style(OpenEnroth)
    target_link_libraries(OpenEnroth PUBLIC application library_cli library_platform_main)

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT OpenEnroth)
endif()
