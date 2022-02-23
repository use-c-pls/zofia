/* Author @daoluke */
#ifndef ZOFIA_DRAWABLE_ENTITY_CPP
#define ZOFIA_DRAWABLE_ENTITY_CPP

#include "PositionEntity.cpp"
#include "IDrawable.cpp"

namespace zofia {
    class DrawableEntity : public PositionEntity, public IDrawable {
        protected:
          DrawableEntity() : PositionEntity(0, 0, true), IDrawable() {

          }

          explicit DrawableEntity(Position pos) : PositionEntity(pos, true), IDrawable() {

          }
    };
}

#endif