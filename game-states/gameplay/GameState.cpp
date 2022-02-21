/* Author @daoluke */
#ifndef ZOFIA_GAME_STATE_CPP__
#define ZOFIA_GAME_STATE_CPP__

#include <SFML/Graphics.hpp>
#include "../StateManager.cpp"

#include "../../world/spaceship/SpaceShip.cpp"

namespace zofia {

    class GameState : public BaseState {
        private:
          SpaceShip m_player;
        public:
          GameState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : BaseState(machine, window, replace) {
              LOG_INFO("GameState is created");
          }

          virtual ~GameState() = default;

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
              m_player.randomHitBox();
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_player.drawHitBox(m_window);
              m_window.display();
          }
    };
}

#endif