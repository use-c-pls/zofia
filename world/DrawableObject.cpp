/* Author @daoluke */
#ifndef ZOFIA_DRAWABLE_OBJECT_CPP
#define ZOFIA_DRAWABLE_OBJECT_CPP

#include "Object.cpp"

namespace zofia {
    template<typename DrawableType>
    class DrawableObject : public Object {
        public:
          DrawableObject() : Object(0, 0, true) {};

          DrawableObject(float x, float y) : Object(x, y, true) {};

          virtual DrawableType getDrawableObject() = 0;
    };
}

#endif