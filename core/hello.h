/* Author @daoluke */
#include <iostream>
#include <SFML/Graphics.hpp>

namespace zofia {
    class hello {
        public:
          static void greeting();
          static sf::Text createText(std::string string, sf::Font &font);
    };
}

