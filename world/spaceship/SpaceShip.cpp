/* Author @daoluke */
#ifndef ZOFIA_BASE_SPACESHIP_CPP
#define ZOFIA_BASE_SPACESHIP_CPP

#include "../../core/logging/logging.hpp"
#include "../HitBoxObject.cpp"

namespace zofia {
    class SpaceShip { //: public DrawableObject
          using HBox = HitBoxObject<302, 76, 0, 0>;
        private:
          HBox m_hitBox{};
        public:
          SpaceShip() {
              LOG_DEBUG("Created base space ship");
          }

          HBox getHitBox() {
              return m_hitBox;
          }

          sf::FloatRect getHitBoxLocalBound() {
              return m_hitBox.getLocalBound();
          }

          void updateHitBoxPos(float x, float y) {
              m_hitBox.setPosition(x, y);
          }

          void updateColor(sf::Color color) {
              m_hitBox.setColor(color);
          }

          void updateHitBoxOrigin(float x, float y) {
              m_hitBox.setOrigin(x, y);
          }

          void randomHitBox() {
              float x = rand() % 2000;
              float y = rand() % 2000;

              updateHitBoxPos(x, y);
          }

          void drawHitBox(sf::RenderWindow &window) {
              window.draw(m_hitBox.getDrawableObject());
          }
    };
}

#endif