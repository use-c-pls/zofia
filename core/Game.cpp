/* Author @daoluke */
#ifndef ZOFIA_GAME_CPP__
#define ZOFIA_GAME_CPP__

#include <SFML/Graphics/RenderWindow.hpp>

#include "../logging/logging.hpp"

#include "state/BlankState.cpp"
#include "state/StateFactory.cpp"
#include "state/StateManager.cpp"

#include "Config.cpp"
#include "Constant.cpp"

namespace zofia {
    class Game {
        private:
          StateManager m_stateMachine{};
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
    m_stateMachine.run(zofia::StateFactory::build<BlankState>(m_stateMachine, m_window, true));
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
#endif