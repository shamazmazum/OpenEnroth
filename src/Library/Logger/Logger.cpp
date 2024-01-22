#include "Logger.h"

#include <cassert>

#include "LogSink.h"
#include "LogSource.h"

Logger *logger = nullptr;

Logger::Logger(LogLevel level, LogSink *sink): _defaultCategory({}) {
    assert(sink);

    _defaultCategory._level = level;
    _sink = sink;

    assert(logger == nullptr);
    logger = this;
}

Logger::~Logger() {
    assert(logger == this);
    logger = nullptr;
}

void Logger::writeToSink(const LogCategory &category, LogLevel level, std::string output) {
    _sink->write(category, level, output);
}

LogLevel Logger::level() const {
    return *_defaultCategory._level;
}

void Logger::setLevel(LogLevel level) {
    if (*_defaultCategory._level == level)
        return;

    _defaultCategory._level = level;

    for (const LogCategory *category : LogCategory::instances())
        if (category->_source && !category->_level)
            category->_source->setLevel(level);
}

std::optional<LogLevel> Logger::level(const LogCategory &category) const {
    return category._level;
}

void Logger::setLevel(LogCategory &category, std::optional<LogLevel> level) {
    if (category._level == level)
        return;

    category._level = level;

    if (category._source) {
        LogLevel effectiveLevel = level ? *level : *_defaultCategory._level;
        category._source->setLevel(effectiveLevel);
    }
}

LogSink *Logger::sink() const {
    return _sink;
}

void Logger::setSink(LogSink *sink) {
    assert(sink);
    _sink = sink;
}
