/* Author @daoluke */
#ifndef ZOFIA_GAME_CPP__
#define ZOFIA_GAME_CPP__

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../game-states/base.hpp"
#include "../game-states/intro/intro.hpp"
#include "../game-states/menu/menu.hpp"

#include "Size.cpp"

namespace zofia {
    class Game {
        private:
          StateManager m_stateMachine;
          sf::RenderWindow m_window;


          void startEngine();

        public:
          explicit Game(Config config);

          virtual ~Game();

          void runWithState(std::unique_ptr<BaseState> state);

          void run();

          void runExample();
    };
}

sf::VideoMode createVideoMode(zofia::Size size) {
    return {static_cast<unsigned int>(size.getWidth()), static_cast<unsigned int>(size.getHeight())};
}

zofia::Game::Game(Config config) : m_stateMachine(config) {
    Size size(config.getWidth(), config.getHeight());
    m_window.create(createVideoMode(size), TITLE, sf::Style::Titlebar | sf::Style::Close);
}

zofia::Game::~Game() {
    LOG_INFO("Cleaning up and closing Game....");
}

void zofia::Game::startEngine() {
    while (m_stateMachine.isRunning()) {
        m_stateMachine.nextState();
        m_stateMachine.processEvents();
        m_stateMachine.update();
        m_stateMachine.draw();
    }
}

void zofia::Game::runWithState(std::unique_ptr<BaseState> state) {
    m_stateMachine.run(std::move(state));
    this->startEngine();
}

void zofia::Game::runExample() {
    runWithState(zofia::StateFactory::build<MenuState>(m_stateMachine, m_window, true));
}

void zofia::Game::run() {
    runWithState(zofia::StateFactory::build<IntroState>(m_stateMachine, m_window, true));
}

#endif