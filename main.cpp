#include <SFML/Graphics.hpp>
#include "core/core.hpp"

const int WIDTH = 1200;
const int HEIGHT = 1800;

int main() {
    zofia::Greeting::greeting("Luke");
    zofia::Game game(zofia::Size(WIDTH, HEIGHT));
    game.run();
    return 0;
}