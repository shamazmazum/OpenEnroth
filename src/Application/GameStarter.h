#pragma once

#include <memory>

#include "GameStarterOptions.h"

class Platform;
class Environment;
class Logger;
class BufferLogSink;
class LogSink;
class PlatformApplication;
class GameConfig;
class Game;

class GameStarter {
 public:
    explicit GameStarter(GameStarterOptions options);
    ~GameStarter();

    PlatformApplication *application() const {
        return _application.get();
    }

    GameConfig *config() const {
        return _config.get();
    }

    void run();

 private:
    static void resolvePaths(Environment *environment, GameStarterOptions* options, Logger *logger);

 private:
    GameStarterOptions _options;
    std::unique_ptr<Environment> _environment;
    std::unique_ptr<BufferLogSink> _bufferLogSink;
    std::unique_ptr<LogSink> _defaultLogSink;
    std::unique_ptr<Logger> _logger;
    std::shared_ptr<GameConfig> _config;
    std::unique_ptr<Platform> _platform;
    std::unique_ptr<PlatformApplication> _application;
    std::shared_ptr<Game> _game;
};
