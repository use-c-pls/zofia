/* Author @daoluke */
#ifndef ZOFIA_HITBOX_OBJECT_CPP
#define ZOFIA_HITBOX_OBJECT_CPP

#include "../core/logging/logging.hpp"
#include "DrawableObject.cpp"

namespace zofia {

    template<int16_t w, int16_t h, int16_t xOff = 0, int16_t yOff = 0>
    class HitBoxObject : public DrawableObject<sf::RectangleShape> {
          static_assert(w > 0 && h > 0, "Invalid width or height for HitBoxObject");
        private:
          sf::RectangleShape m_rect;

        public:
          HitBoxObject() {
              m_rect.setFillColor(sf::Color::Transparent);
              m_rect.setOutlineColor(sf::Color::Red);
              m_rect.setOutlineThickness(1);
              m_rect.setSize(sf::Vector2f(w, h));
          }

          sf::FloatRect getLocalBound() {
              return m_rect.getLocalBounds();
          }

          void setOrigin(float x, float y) {
              m_rect.setOrigin(x, y);
          }

          void setColor(sf::Color color) {
              m_rect.setOutlineColor(color);
          }

          void setPosition(const Position &pos) {
              float x = pos.getXAxis();
              float y = pos.getYAxis();

              m_position.setXAxis(x);
              m_position.setYAxis(y);

              m_rect.setPosition(x + xOff, y + yOff);
          }

          void setPosition(float x, float y) {
              setPosition(Position(sf::Vector2f{x, y}));
          }

          sf::RectangleShape getDrawableObject() override {
              return this->m_rect;
          }

          float getXPos() {
              return m_position.getXAxis();
          }

          float getYPos() {
              return m_position.getYAxis();
          }

          int16_t getWidth() {
              return w;
          }

          int16_t getHeight() {
              return h;
          }
    };
}

#endif