/* Author @daoluke */
#ifndef ZOFIA_GAME_STATE_CPP__
#define ZOFIA_GAME_STATE_CPP__

#include <SFML/Graphics.hpp>
#include "../StateManager.cpp"

#include "../../world/spaceship/SpaceShip.cpp"

namespace zofia {

    class GameState : public BaseState {
        private:
          SpaceShip m_player1;
          SpaceShip m_player2;
        public:
          GameState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : BaseState(machine, window, replace) {
              LOG_INFO("GameState is created");
              m_player1.updateColor(sf::Color::Red);
              m_player2.updateColor(sf::Color::Green);
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
              m_player1.randomHitBox();
              m_player2.randomHitBox();

              if (m_player1.isHit(m_player2)) {
                  std::stringstream log;
                  log << "Player 1 hits player 2. ";
                  log << "Player 1 Pos:" << m_player1.getHitBox().getPosition().toString();
                  log << "; ";
                  log << "Player 2 Pos:" << m_player2.getHitBox().getPosition().toString();

                  LOG_DEBUG(log.str());
              }
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_player1.drawHitBox(m_window);
              m_player2.drawHitBox(m_window);
              m_window.display();
          }
    };
}

#endif