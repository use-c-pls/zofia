/* Author @daoluke */
#ifndef ZOFIA_GAME_CPP__
#define ZOFIA_GAME_CPP__

#include <SFML/Graphics.hpp>

#include "Size.cpp"
#include "Config.cpp"
#include "Constant.cpp"

#include "../logging/logging.hpp"

#define ZOFIA zofia::

namespace zofia {
    class Game {
        private:
          const std::string TITLE = "Zofia";

          zofia::Logging LOG;

          sf::RenderWindow m_window;
          sf::Event m_sfEvent{};

          Size m_size;

          void updateSfEvent();

        public:
          Game() : Game(Size(zofia::DEFAULT_GAME_WIDTH, zofia::DEFAULT_GAME_HEIGHT)) {}

          explicit Game(Size size) : m_size(size.getWidth(), size.getHeight()),
                                     m_window(sf::VideoMode(size.getWidth(), size.getHeight()), TITLE) {
              this->LOG.info("Running game " + TITLE);
          }

          explicit Game(Config *config) : m_size(config->getWidth(), config->getHeight()),
                                          m_window(sf::VideoMode(config->getWidth(), config->getHeight()), TITLE) {
              std::cout << "Address config 2 #" << config << std::endl;
              this->LOG.info("Using config to running game " + TITLE);
          }

          virtual ~Game();

          std::string getTitle() const {
              return TITLE;
          }

          Size getSize() const {
              return m_size;
          }

          void run();
          void update();
          void render();
    };
}

ZOFIA Game::~Game() {
    this->LOG.info("Cleaning up GameEngine ...");
}

void ZOFIA Game::updateSfEvent() {
    while (this->m_window.pollEvent(this->m_sfEvent)) {
        // "close requested" event: we close the window
        if (this->m_sfEvent.type == sf::Event::Closed)
            this->m_window.close();
    }
}

void ZOFIA Game::run() {
    while (this->m_window.isOpen()) {
        this->update();
        this->render();
    }
}

void ZOFIA Game::update() {
    this->updateSfEvent();
}

void ZOFIA Game::render() {
    this->m_window.clear();

    // draw everything here...

    this->m_window.display();
}
#endif