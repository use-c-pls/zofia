/* Author @daoluke */
#ifndef ZOFIA_MENU_SCENE_CPP__
#define ZOFIA_MENU_SCENE_CPP__

#include "../Game.cpp"
#include "StateManager.cpp"
#include "StateFactory.cpp"

namespace zofia {
    class MenuState final : public BaseState {
        private:
          Typography m_typo;
        public:
          MenuState(StateManager &machine, sf::RenderWindow &window, bool replace = true) : BaseState(machine, window,
                                                                                                      replace),
                                                                                            m_typo(window) {
              LOG_INFO("MenuState is created");
          };

          virtual ~MenuState() = default;

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