#include "core/core.hpp"
#include "menu/MenuScene.cpp"

int main() {
    zofia::Config config;
    std::cout << config.getKeyBinding("up");

    zofia::Greeting::greeting("Luke");

    std::cout << "Address Config 1 #" << &config << std::endl;
    zofia::Game game(&config);
    zofia::MenuScene menuScene(&game);
    std::cout << "Address Game 2 #" << &game << std::endl;

    game.run();

    return 0;
}