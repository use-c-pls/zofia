#include "core/core.hpp"
#include "menu/MenuScene.cpp"
#include "logging/StoutLogging.cpp"

const int WIDTH = 1200;
const int HEIGHT = 1800;

int main() {
    zofia::Config config;
    std::cout << config.getKeyUp() << std::endl;
    zofia::Greeting::greeting("Luke");
    zofia::Game game(zofia::Size(WIDTH, HEIGHT));
    zofia::MenuScene menuScene(&game);

    zofia::StoutLogging log;
    log.changeLogLevel("debug");
    log.debug("OK");

    game.run();

    return 0;
}