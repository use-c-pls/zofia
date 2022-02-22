/* Author @daoluke */
#ifndef ZOFIA_MENU_SCENE_CPP__
#define ZOFIA_MENU_SCENE_CPP__

#include <SFML/Graphics.hpp>
namespace zofia {
    class MenuState final : public BaseState {
        private:
          Rectangle m_background;
          std::vector<Button*> m_buttons;
        public:
          MenuState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : BaseState(machine, window, replace),
                    m_background(window, "resources/backgrounds/menu_background.jpg",
                                 Size(1920, 1080), Position(0, 0)) {
              m_buttons.push_back(new Button(window,"Start",Position(0,0),Size(302,76)));
              m_buttons.push_back(new Button(window,"Setting",Position(0,0),Size(302,76)));
              m_buttons.push_back(new Button(window,"Quit",Position(0,0),Size(302,76)));
              m_buttons[0]->center(m_background);

              m_buttons[1]->center(m_background);
              m_buttons[2]->center(m_background);

              m_buttons[0]->marginBottom(200);
              m_buttons[1]->marginBottom(100);

              m_buttons[0]->alignText(zofia::CENTER_TEXT);
              m_buttons[1]->alignText(zofia::CENTER_TEXT);
              m_buttons[2]->alignText(zofia::CENTER_TEXT);

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
//              LOG_DEBUG("MenuState update")

          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_background.draw();
              for(auto each : m_buttons){
                  each->draw();
              }
              m_window.display();
          }
    };
}

#endif