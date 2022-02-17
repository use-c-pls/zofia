/* Author @daoluke */
#ifndef ZOFIA_MENU_SCENE_CPP__
#define ZOFIA_MENU_SCENE_CPP__

#include <SFML/Graphics.hpp>

namespace zofia {
    class MenuState final : public BaseState {
        private:
          Typography m_typo;
          Rectangle m_background;
        public:
          MenuState(StateManager &machine, sf::RenderWindow &window, bool replace = true) : BaseState(machine, window, replace), m_typo(window),
                                                                                            m_background(window,
                                                                                                         "resources/backgrounds/menu_background.png",
                                                                                                         Size(1920, 1080), Position(0, 0)) {
              LOG_INFO("MenuState is created");
          };

          virtual ~MenuState() = default;

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
              //LOG_DEBUG("MenuState update");
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_background.draw();
              //m_typo.draw();
              m_window.display();
          }
    };
}

#endif