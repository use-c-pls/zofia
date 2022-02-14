/* Author @daoluke */
#ifndef ZOFIA_APPLICATION_CPP__
#define ZOFIA_APPLICATION_CPP__

#include "../config/Config.cpp"
#include "Game.cpp"

namespace zofia {
    class Application {
        public:
          void run(const std::string &configPath);
    };
}

void zofia::Application::run(const std::string &configPath = zofia::DEFAULT_CONFIG_PATH) {
    // enabled debug
    zofia::CORE_LOGGER.changeLogLevel("Debug");

    LOG_INFO("Starting application {}....", zofia::TITLE);
    LOG_INFO("Read config from `{}`", configPath);

    zofia::Config config(configPath);
    zofia::Game game(config);

    game.run();
}

#endif