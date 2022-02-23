/* Author @daoluke */
#ifndef ZOFIA_BASE_SPACESHIP_CPP
#define ZOFIA_BASE_SPACESHIP_CPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../../include/core/config.hpp"
#include "../../include/core/logging.hpp"

#include "../util/Speed.cpp"
#include "../DrawableEntity.cpp"
#include "../HitBoxObject.cpp"

namespace zofia {
    class SpaceShip : DrawableEntity {
          using HBox = HitBoxObject;
        private:
          HBox m_hitBox{};
          Speed m_speed{};
        public:
          SpaceShip() : DrawableEntity() {
              m_hitBox = HBox(DEFAULT_HIT_BOX["space_ship_hit_box"]);
              m_speed = Speed(20, 0);
              LOG_DEBUG("Created base space ship");
          }

          void draw(sf::RenderTarget &target) override {

          }

          HBox getHitBox() const {
              return m_hitBox;
          }

          sf::FloatRect getHitBoxLocalBound() {
              return m_hitBox.getLocalBounds();
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

          void moveLeft() {
              m_hitBox.move(m_speed.get().x * -1);
          }

          void moveRight() {
              m_hitBox.move(m_speed.get().x);
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