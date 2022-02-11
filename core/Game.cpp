/* Author @daoluke */
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Size.cpp"
#define ZOFIA zofia::

namespace zofia {
    class Game {
        private:
          const std::string TITLE = "Zofia";

          sf::RenderWindow m_window;
          sf::Event m_sfEvent{};

          Size m_size;

          void updateSfEvent();

        public:
          Game() : Game(Size(600, 800)) {}

          explicit Game(Size size) : m_size(size.getWidth(), size.getHeight()),
                                     m_window(sf::VideoMode(size.getWidth(), size.getHeight()), TITLE) {
              std::cout << "Running game " << TITLE << std::endl;
              std::cout << "Size: {w: " << size.getWidth() << ", h: " << size.getHeight() << "}" << std::endl;
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
    std::cout << "Cleaning up...";
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