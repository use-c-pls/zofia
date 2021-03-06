/* Author @daoluke */
#ifndef ZOFIA_INTRO_STATE_CPP__
#define ZOFIA_INTRO_STATE_CPP__

#include <SFML/Graphics.hpp>
#include "../../include/world/widget.hpp"
#include "../gameplay/GameState.cpp"
#include "../StateFactory.cpp"

namespace zofia {
    class IntroState final : public BaseState {
        private:
          Button m_button;
        public:
          IntroState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : BaseState(machine, window, replace),
                    m_button("Hello world", Position(0, 0), Size(300, 400)) {
              LOG_INFO("IntroState is created");

              m_button.setId("hello_btn");
          }

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

          void update(sf::Time deltaTime) override {
              auto val = std::to_string(deltaTime.asSeconds());
//              LOG_DEBUG("Intro update with {}", val);
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_button.draw(m_window);
              m_window.display();
          }
    };
}
#endif