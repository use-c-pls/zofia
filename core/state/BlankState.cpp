/* Author @daoluke */
#ifndef ZOFIA_INTRO_STATE_CPP__
#define ZOFIA_INTRO_STATE_CPP__
#include <SFML/Graphics.hpp>
#include "../../entities/Typography.cpp"
#include "StateManager.cpp"

namespace zofia {
    class BlankState final : public BaseState {
    private:
        Typography* typo;
        public:
          BlankState(StateManager &machine, sf::RenderWindow &window, bool replace = true) : BaseState(machine,
                                                                                                       window,
                                                                                                       replace) {
              this->typo = new Typography(this->m_window,"resources/fonts/arial.ttf");
              LOG_INFO("BlankState is created");
          };

          void pause() override {
          }
          void resume() override {

          }

          void processEvents() override {
              sf::Event event{};
              while (m_window.pollEvent(event)) {
                  // "close requested" event: we close the window
                  if (event.type == sf::Event::Closed) {
                      m_manager.quit();
                      m_window.close();
                  }
              }
          }

          void update() override {
              LOG_DEBUG("BlankState updating");
          }

          void draw() override {
              m_window.clear(sf::Color::Black);


              typo->draw();
              m_window.display();
          }
    };
}
#endif