/* Author @daoluke */
#ifndef ZOFIA_GAME_STATE_CPP__
#define ZOFIA_GAME_STATE_CPP__

#include <SFML/Graphics.hpp>

#include "../../include/world/full.hpp"

#include "../StateManager.cpp"

namespace zofia {

    class GameState final : public BaseState {
        private:
          SpaceShip m_player1;
          SpaceShip m_player2;
          FpsCounter m_fpsCounter;
        public:
          GameState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : BaseState(machine, window, replace), m_fpsCounter() {
              LOG_INFO("GameState is created");
              m_player1.updateColor(sf::Color::Red);
              m_player2.updateColor(sf::Color::Green);

              m_player1.updateHitBoxPos(200, 200);
              m_player2.updateHitBoxPos(300, 300);
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
                  } else if (event.type == sf::Event::KeyPressed) {
                      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                          m_player1.moveRight();
                      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                          m_player1.moveLeft();
                      }
                  }
              }
          }

          void update(sf::Time deltaTime) override {
              FpsCounterContext context;
              m_fpsCounter.update(context);
          }


          void draw() override {
              m_window.clear(sf::Color::Black);
              m_player1.drawHitBox(m_window);
              m_player2.drawHitBox(m_window);
              m_fpsCounter.draw(m_window);
              m_window.display();
          }
    };
}

#endif