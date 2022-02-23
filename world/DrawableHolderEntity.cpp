/* Author @daoluke */
#ifndef ZOFIA_DRAWABLE_HOLDER_ENTITY_CPP
#define ZOFIA_DRAWABLE_HOLDER_ENTITY_CPP

#include "PositionEntity.cpp"

namespace zofia {
    template<typename DrawableType>
    class DrawableHolderEntity : public PositionEntity {
        public:
          DrawableHolderEntity() : PositionEntity(0, 0, true) {};

          DrawableHolderEntity(float x, float y) : PositionEntity(x, y, true) {};

          virtual DrawableType getDrawableObject() = 0;
    };
}

#endif