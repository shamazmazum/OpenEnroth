cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

set(ENGINE_GRAPHICS_LEVEL_SOURCES
        Decoration.cpp)

set(ENGINE_GRAPHICS_LEVEL_HEADERS
        Decoration.h)

add_library(engine_graphics_level STATIC ${ENGINE_GRAPHICS_LEVEL_SOURCES} ${ENGINE_GRAPHICS_LEVEL_HEADERS})
target_check_style(engine_graphics_level)

target_link_libraries(engine_graphics_level
  PUBLIC
  engine
  engine_graphics
  engine_graphics_renderer
  utility
  library_serialization
  library_color
  library_image
  OpenGL::GL
  engine_graphics
  PRIVATE
  ${LuaJit_LDFLAGS}
  glad
)

target_include_directories(engine_graphics_level PRIVATE
  ${LuaJit_INCLUDE_DIRS}
  ${GLM_INCLUDE_DIR}
)
