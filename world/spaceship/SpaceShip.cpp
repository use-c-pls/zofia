/* Author @daoluke */
#ifndef ZOFIA_BASE_SPACESHIP_CPP
#define ZOFIA_BASE_SPACESHIP_CPP

#include "../../core/logging/logging.hpp"
#include "../HitBoxObject.cpp"

namespace zofia {
    class SpaceShip { //: public DrawableObject
          using HBox = HitBoxObject<200, 200, 200, 200>;
        private:
          HBox m_hitBox{};
        public:
          SpaceShip() {
              LOG_DEBUG("Created base space ship");
          }

          HBox getHitBox() {
              return m_hitBox;
          }

          void updateHitBoxPos(float x, float y) {
              m_hitBox.setPosition(x, y);
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