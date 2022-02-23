/* Author @daoluke */
#ifndef ZOFIA_I_DRAWABLE_CPP
#define ZOFIA_I_DRAWABLE_CPP

#include <SFML/Graphics/RenderTarget.hpp>

namespace zofia {
    class IDrawable {
        public:
          virtual void draw(sf::RenderTarget &target) = 0;
    };
}

#endif