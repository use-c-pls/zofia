#include <SFML/Graphics.hpp>
#include "core/hello.cpp"

int main() {
    // create the window
    zofia::hello::greeting();
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Font font;

    sf::Text text;
    if (font.loadFromFile("resources/fonts/arial.ttf")) {
        text = zofia::hello::createText("Hello", font);
    }
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear();

        // draw everything here...

        window.draw(text);
        // end the current frame
        window.display();
    }
    return 0;
}