/* Author @daoluke */
#include <iostream>
#include <SFML/Graphics.hpp>

namespace zofia {
    class hello {
        public:
          static void greeting() {
              std::cout << "Hello, World";
          }

          static sf::Text createText(std::string string, sf::Font &font) {
              sf::Text text;

              text.setString(string);
              text.setCharacterSize(56); // in pixels, not points!
              text.setFillColor(sf::Color::Red);
              text.setStyle(sf::Text::Bold | sf::Text::Underlined);
              text.setFont(font);

              return text;
          }
    };
}
