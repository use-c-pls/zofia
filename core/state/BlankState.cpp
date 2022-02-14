/* Author @daoluke */
#ifndef ZOFIA_INTRO_STATE_CPP__
#define ZOFIA_INTRO_STATE_CPP__

#include <SFML/Graphics.hpp>

#include "../../entities/Typography.cpp"
#include "StateManager.cpp"

namespace zofia {
    class BlankState final : public BaseState {
        private:
          Typography m_typo;
        public:
          BlankState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
              : BaseState(machine, window, replace), m_typo(window) {
              LOG_INFO("BlankState is created");
          };

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
              int val = rand() % 100 + 1;
              std::string str = "Random: " + std::to_string(val) + "\n";
              m_typo.updateText(str);
              LOG_DEBUG("BlankState updating");
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_typo.draw();
              m_window.display();
          }
    };
}
#endif