//
// Created by kienle on 17/02/2022.
//

#ifndef ZOFIA_POSITION_CPP__
#define ZOFIA_POSITION_CPP__

#include <SFML/Graphics.hpp>

namespace zofia {
    class Position {
        private:
          sf::Vector2f m_position{};
        public:
          explicit Position() = default;

          Position(int x, int y) {
              m_position.x = (float) x;
              m_position.y = (float) y;
          };

          Position(const sf::Vector2f &pos) {
              m_position.x = pos.x;
              m_position.y = pos.y;
          }

          float getXAxis() const {
              return this->m_position.x;
          }

          void setXAxis(float x) {
              this->m_position.x = x;
          }

          float getYAxis() const {
              return this->m_position.y;
          }

          void setYAxis(float y) {
              this->m_position.y = y;
          }

          void set(const sf::Vector2f &pos) {
              setXAxis(pos.x);
              setYAxis(pos.y);
          }

          sf::Vector2f getAsVector2f() const {
              return this->m_position;
          }
    };
}
#endif