/* Author @daoluke */
#ifndef ZOFIA_OBJECT_CPP
#define ZOFIA_OBJECT_CPP

#include "../include/core/core.hpp"

namespace zofia {

    class Object {
        private:
          bool m_drawable;
        protected:
          Position m_position;
        public:
          Object() : m_position(0, 0), m_drawable(false) {

          }

          Object(float x, float y) : m_position(sf::Vector2f{x, y}), m_drawable(false) {

          }

          Object(float x, float y, bool drawable) : m_position(sf::Vector2f{x, y}), m_drawable(drawable) {

          }

          virtual ~Object() = default;

          bool isDrawable() const {
              return m_drawable;
          }

          Position getPosition() const {
              return m_position;
          }
    };
}

#endif
