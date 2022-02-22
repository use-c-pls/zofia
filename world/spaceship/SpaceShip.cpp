/* Author @daoluke */
#ifndef ZOFIA_BASE_SPACESHIP_CPP
#define ZOFIA_BASE_SPACESHIP_CPP

#include "../../include/core/config.hpp"
#include "../../include/core/logging.hpp"
#include "../HitBoxObject.cpp"

namespace zofia {
    class SpaceShip { //: public DrawableObject
          using HBox = HitBoxObject;
        private:
          HBox m_hitBox{};
        public:
          SpaceShip() {
              m_hitBox = HBox(DEFAULT_HIT_BOX["space_ship_hit_box"]);
              LOG_DEBUG("Created base space ship");
          }

          HBox getHitBox() const {
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

          void updateHitBoxSize(int w, int h) {
              m_hitBox.setHitBoxSize(w, h);
          }

          bool isHit(SpaceShip &another) const {
              return this->getHitBox().isHit(another.getHitBox());
          }

          void randomHitBox() {
              float x = rand() % 2000;
              float y = rand() % 2000;

              updateHitBoxPos(x, y);
          }

          void drawHitBox(sf::RenderTarget &window) {
              window.draw(m_hitBox.getDrawableObject());
          }
    };
}

#endif