/* Author @daoluke */
#ifndef ZOFIA_GAME_CPP__
#define ZOFIA_GAME_CPP__

#include <SFML/Graphics/RenderWindow.hpp>

#include "../logging/logging.hpp"

#include "state/IntroState.cpp"
#include "state/StateMachine.cpp"

#include "Config.cpp"
#include "Constant.cpp"

namespace zofia {
    class StateFactory {
        public:
          StateFactory() = default;
          template<typename T>
          std::unique_ptr<T> build(zofia::StateMachine &machine, sf::RenderWindow &window, bool replace = true);
    };

    class Game {
        private:
          StateFactory m_stateFactory;
          StateMachine m_stateMachine{};
          sf::RenderWindow m_window;
        public:
          explicit Game(Config config);
          virtual ~Game();
          void run();
    };
}
zofia::Game::Game(Config config) {
    m_window.create(sf::VideoMode(config.getWidth(), config.getHeight()),
                    TITLE,
                    sf::Style::Titlebar | sf::Style::Close);
    m_stateMachine.run(m_stateFactory.build<IntroState>(m_stateMachine, m_window, true));
}

zofia::Game::~Game() {
    LOG_INFO("Cleaning up and closing Game....");
}

void zofia::Game::run() {
    while (m_stateMachine.isRunning()) {
        m_stateMachine.nextState();
        m_stateMachine.processEvents();
        m_stateMachine.update();
        m_stateMachine.draw();
    }
}
// -----------
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args);

template<typename T>
std::unique_ptr<T> zofia::StateFactory::build(zofia::StateMachine &machine, sf::RenderWindow &window, bool replace) {
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