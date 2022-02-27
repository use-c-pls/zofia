/* Author @daoluke */
#ifndef ZOFIA_MENU_SCENE_CPP__
#define ZOFIA_MENU_SCENE_CPP__

#include <SFML/Graphics.hpp>

namespace zofia {
    class MenuState final : public BaseState {
        private:
          Rectangle m_background;
          MenuStack m_menuStack;

        public:
          MenuState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : m_menuStack(), BaseState(machine, window, replace),
                    m_background("resources/backgrounds/menu_background.jpg",
                                 Size(zofia::Display::WIDTH, zofia::Display::HEIGHT), Position(0, 0)) {

              m_menuStack.center(m_background);

              m_menuStack.setFunc("quit", [&]() {
                  m_manager.quit();
                  m_window.close();
              });

              m_menuStack.setFunc("start", [&]() {
                  m_manager.run(std::move(StateFactory::build<GameState>(m_manager, m_window, true)));
              });

              LOG_INFO("MenuState is created");
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
                  m_menuStack.handleEvent(m_window, event);
              }
          }

          void update(sf::Time deltaTime) override {
              auto val = std::to_string(deltaTime.asSeconds());
//              LOG_DEBUG("MenuState update with {}", val);
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_background.draw(m_window);
              m_menuStack.draw(m_window);
              m_window.display();
          }
    };
}

#endif