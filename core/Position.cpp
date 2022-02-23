//
// Created by kienle on 17/02/2022.
//

#ifndef ZOFIA_POSITION_CPP__
#define ZOFIA_POSITION_CPP__

#include <sstream>
#include <SFML/System/Vector2.hpp>

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

          explicit Position(const sf::Vector2f &pos) {
              m_position.x = pos.x;
              m_position.y = pos.y;
          }

          Position(float x, float y) {
              m_position.x = x;
              m_position.y = y;
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

          bool operator==(const Position &anotherPos) const {
              return this->getXAxis() == anotherPos.getXAxis()
                     && this->getYAxis() == anotherPos.getYAxis();
          }

          std::string toString() {
              std::stringstream res;
              res << "{ x: " << getXAxis() << ", y: " << getYAxis() << "}";
              return res.str();
          }
    };
}
#endif