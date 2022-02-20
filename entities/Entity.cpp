//
// Created by kienle on 13/02/2022.
//

#ifndef ZOFIA_ET_CPP__
#define ZOFIA_ET_CPP__

#include <SFML/Graphics/RenderWindow.hpp>

#define ZOFIA zofia::
namespace zofia {
    class Entity {
        protected:

          sf::RenderWindow &m_window;
        public:
          explicit Entity(sf::RenderWindow &window) : m_window{window} {
          }

          Entity() = default;

          virtual void draw() = 0;
    };
}
#endif