cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

set(LIBRARY_LOGGER_SOURCES
        LogCategory.cpp
        LogEnums.cpp
        Logger.cpp
        LogSink.cpp)

set(LIBRARY_LOGGER_HEADERS
        BufferLogSink.h
        LogCategory.h
        LogEnums.h
        Logger.h
        LogSink.h
        LogSource.h)

add_library(library_logger STATIC ${LIBRARY_LOGGER_SOURCES} ${LIBRARY_LOGGER_HEADERS})
target_link_libraries(library_logger PUBLIC library_serialization utility PRIVATE ${SPDLOG_LDFLAGS})
target_include_directories(library_logger PRIVATE ${SPDLOG_INCLUDE_DIRS})
target_compile_definitions(library_logger PRIVATE
  SPDLOG_FMT_EXTERNAL SPDLOG_DISABLE_DEFAULT_LOGGER SPDLOG_WCHAR_SUPPORT)
target_check_style(library_logger)
