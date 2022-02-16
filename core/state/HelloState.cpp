//
// Created by kienle on 16/02/2022.
//

#ifndef ZOFIA_HELLO_STATE_CPP__
#define ZOFIA_HELLO_STATE_CPP__

#include <SFML/Graphics.hpp>

#include "../../entities/Typography.cpp"
#include "StateManager.cpp"

namespace zofia {
    class HelloState final : public BaseState {
        private:
          Typography m_typo;
        public:
          HelloState(StateManager &machine, sf::RenderWindow &window, bool replace = true) : BaseState(machine, window, replace), m_typo(window) {

              LOG_INFO("HelloState is created");
          };

          virtual ~HelloState() = default;

          void pause() override {
          }

          void resume() override {

          }

          void processEvents() override {
              sf::Event event;
              while (m_window.pollEvent(event)) {
                  if (event.type == sf::Event::Closed) {
                      m_manager.quit();
                      m_window.close();
                  } else if (event.type == sf::Event::KeyPressed) {
                      if (event.key.code == sf::Keyboard::Enter) {
                          //Process enter pressed
                          //m_next = zofia::StateFactory::build<MenuState>(this->m_manager, m_window, true);
                          LOG_DEBUG("Enter press");
                      }
                  }
              }
          }

          void update() override {

          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_typo.draw();
              m_window.display();
          }
    };
}
#endif