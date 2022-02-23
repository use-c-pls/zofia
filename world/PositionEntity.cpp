/* Author @daoluke */
#ifndef ZOFIA_OBJECT_CPP
#define ZOFIA_OBJECT_CPP

#include "../include/core/core.hpp"
#include "Entity.cpp"

namespace zofia {

    class PositionEntity : public Entity {
        private:
          bool m_drawable;
        protected:
          Position m_position;
        public:
          PositionEntity() : m_position(0, 0), m_drawable(false), Entity() {

          }

          PositionEntity(float x, float y) : m_position(sf::Vector2f{x, y}), m_drawable(false), Entity() {

          }

          PositionEntity(float x, float y, bool drawable)
                  : m_position(sf::Vector2f{x, y}), m_drawable(drawable),
                    Entity() {

          }

          explicit PositionEntity(Position pos) : PositionEntity(pos.getYAxis(), pos.getYAxis()) {

          }

          explicit PositionEntity(Position pos, bool drawable) : PositionEntity(pos.getYAxis(), pos.getYAxis(),
                                                                                drawable) {
          }


          bool isDrawable() const {
              return m_drawable;
          }

          Position getPosition() const {
              return m_position;
          }

          void setPosition(Position pos) {
              m_position.set(pos.getAsVector2f());
          }
    };
}

#endif
