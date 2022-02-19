/* Author @daoluke */
#ifndef ZOFIA_STATE_FACTORY_CPP__
#define ZOFIA_STATE_FACTORY_CPP__

#include <SFML/Graphics/RenderWindow.hpp>
#include "StateManager.cpp"
#include "../core/Util.cpp"

namespace zofia {
    class StateFactory {
        public:
          StateFactory() = default;

          template<typename T>
          static std::unique_ptr<T> build(zofia::StateManager &machine, sf::RenderWindow &window, bool replace = true);
    };
}

// -----------
template<typename T>
std::unique_ptr<T> zofia::StateFactory::build(zofia::StateManager &machine, sf::RenderWindow &window, bool replace) {
    return zofia::build<T>(machine, window, replace);
}

#endif