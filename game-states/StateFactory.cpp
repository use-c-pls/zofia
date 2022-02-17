/* Author @daoluke */
#ifndef ZOFIA_STATE_FACTORY_CPP__
#define ZOFIA_STATE_FACTORY_CPP__

#include <SFML/Graphics/RenderWindow.hpp>
#include "StateManager.cpp"

namespace zofia {
    class StateFactory {
        public:
          StateFactory() = default;

          template<typename T>
          static std::unique_ptr<T> build(zofia::StateManager &machine, sf::RenderWindow &window, bool replace = true);
    };
}

// -----------
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args);

template<typename T>
std::unique_ptr<T> zofia::StateFactory::build(zofia::StateManager &machine, sf::RenderWindow &window, bool replace) {
    auto new_state = std::unique_ptr<T>{nullptr};

    try {
        new_state = make_unique<T>(machine, window, replace);
    }
    catch (std::runtime_error &exception) {
        LOG_ERROR("Creation of new state was unsuccessful\n");
        LOG_ERROR(exception.what());
    }

    return new_state;
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif