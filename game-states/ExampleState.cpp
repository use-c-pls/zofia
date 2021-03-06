/* Author @daoluke */
#ifndef ZOFIA_BLANK_STATE_CPP__
#define ZOFIA_BLANK_STATE_CPP__

#include <SFML/Graphics.hpp>

#include "../include/world/widget.hpp"

#include "StateManager.cpp"

namespace zofia {
    class ExampleState final : public BaseState {
        private:
          Typography m_typo;
        public:
          ExampleState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : BaseState(machine, window, replace), m_typo() {
              LOG_INFO("ExampleState is created");
          };

          virtual ~ExampleState() = default;

          void pause() override {
          }

          void resume() override {

          }

          void processEvents() override {
              sf::Event event{};
              while (m_window.pollEvent(event)) {
                  if (event.type == sf::Event::Closed) {
                      m_manager.quit();
                      m_window.close();
                  }
              }
          }

          void update() override {
              int val = std::rand() % 100 + 1;
              std::string str = "Random: " + std::to_string(val) + "\n";
              TypographyContext context(str, 54);
              m_typo.update(context);
              LOG_DEBUG("ExampleState updating");
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_typo.draw(m_window);
              m_window.display();
          }
    };
}
#endif