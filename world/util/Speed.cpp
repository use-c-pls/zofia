/* Author @daoluke */
#ifndef ZOFIA_SPEED_CPP
#define ZOFIA_SPEED_CPP

#include <SFML/System/Vector2.hpp>

namespace zofia {
    class Speed {
        private:
          sf::Vector2f m_val;
        public:
          Speed() : m_val(0, 0) {}

          // Only move on X-Axis
          Speed(float val) : m_val(val, 0) {}

          // Moving on X with x velocity
          // Moving on Y with y velocity
          Speed(float x, float y) : m_val(x, y) {}

          void update(float x, float y) {
              m_val.x = x;
              m_val.y = y;
          }

          sf::Vector2f get() const {
              return m_val;
          }
    };
}

#endif