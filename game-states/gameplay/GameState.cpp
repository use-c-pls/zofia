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
          SpaceShip m_player3;
        public:
          GameState(StateManager &machine, sf::RenderWindow &window, bool replace = true)
                  : BaseState(machine, window, replace) {
              LOG_INFO("GameState is created");

              float windowWidth = 1920;
              float windowHeight = 1080;

              float marginTopForBtn1 = 200;
              float marginTopForBtn2 = 100;
              float marginTopForBtn3 = 0;

              m_player1.updateColor(sf::Color::Red);
              m_player2.updateColor(sf::Color::Green);
              m_player3.updateColor(sf::Color::Yellow);

              auto lb1 = m_player1.getHitBoxLocalBound();
              auto lb2 = m_player2.getHitBoxLocalBound();
              auto lb3 = m_player3.getHitBoxLocalBound();

              m_player1.updateHitBoxOrigin(lb1.width / 2, 0);
              m_player1.updateHitBoxPos(windowWidth / 2, windowHeight / 2 - marginTopForBtn1);

              m_player2.updateHitBoxOrigin(lb2.width / 2, 0);
              m_player2.updateHitBoxPos(windowWidth / 2, windowHeight / 2 - marginTopForBtn2);

              m_player3.updateHitBoxOrigin(lb3.width / 2, 0);
              m_player3.updateHitBoxPos(windowWidth / 2, windowHeight / 2 - marginTopForBtn3);
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
//              m_player.randomHitBox();
          }

          void draw() override {
              m_window.clear(sf::Color::Black);
              m_player1.drawHitBox(m_window);
              m_player2.drawHitBox(m_window);
              m_player3.drawHitBox(m_window);
              m_window.display();
          }
    };
}

#endif