//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_RECT_CPP__
#define ZOFIA_RECT_CPP__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

#include "../include/core/core.hpp"

#include "util/Margin.cpp"
#include "EntityContext.cpp"
#include "DrawableEntity.cpp"

namespace zofia {
    class RectangleContext : public EntityContext {
        public:
          Size m_size;
          Position m_position;
          Position m_origin;
          sf::Color m_color;
          MarginInfo m_margin;
    };

    class Rectangle : public DrawableEntity {
        private:
          sf::Texture m_texture;
          sf::Sprite m_sprite;
          Size m_size;

          sf::Texture createTexture(std::string path);

          template<typename E>
          RectangleContext cast(E &context);

        public:
          explicit Rectangle(const std::string &pathBackground, const Size &size,
                             const Position &startPosition)
                  : m_size(size), DrawableEntity(startPosition) {
              this->m_texture = createTexture(pathBackground);
              this->m_sprite.setTexture(this->m_texture);
              this->m_sprite.setPosition(startPosition.getXAxis(), startPosition.getYAxis());
          }

          explicit Rectangle(const Size &size, const Position &startPosition)
                  : m_size(size), DrawableEntity(startPosition) {
              this->m_texture.create(size.getWidth(), size.getHeight());
              this->m_sprite.setTexture(this->m_texture);
              this->m_sprite.setPosition(startPosition.getXAxis(), startPosition.getYAxis());
          }

          void draw(sf::RenderTarget &target) override;

          template<typename E>
          void update(E &context);

          sf::Color getColor() const {
              return this->m_sprite.getColor();
          }

          sf::FloatRect getLocalBounds() const {
              return this->m_sprite.getLocalBounds();
          }

          sf::FloatRect getGlobalBounds() const {
              return this->m_sprite.getGlobalBounds();
          }

          sf::Vector2f getOrigin() {
              return this->m_sprite.getOrigin();
          }

          sf::Texture &getTexture() {
              return m_texture;
          }

          sf::Sprite &getSprite() {
              return m_sprite;
          }

          Size &getSize() {
              return m_size;
          }
    };
}

sf::Texture zofia::Rectangle::createTexture(std::string path) {
    sf::Texture texture{};

    sf::Clock clock;//start time
    clock.restart();

    if (!texture.loadFromFile(path)) {
        LOG_ERROR("Not found background at `{}`", path);
    }
    sf::Time start = clock.getElapsedTime();
    float cost = start.asSeconds();
    LOG_DEBUG("Time load image {} | cost: {} second", path, cost);
    texture.setRepeated(false);
    return texture;
}

void zofia::Rectangle::draw(sf::RenderTarget &target) {
    target.draw(this->m_sprite);
}

template<typename E>
void zofia::Rectangle::update(E &c) {
    RectangleContext context = cast(c);

    float xPosition = 0;
    float yPosition = 0;
    switch (context.m_margin.type) {
        case zofia::Margin::TOP: {
            yPosition += context.m_margin.value;
            break;
        }
        case zofia::Margin::BOTTOM: {
            yPosition -= context.m_margin.value;
            break;
        }
        case zofia::Margin::LEFT: {
            xPosition += context.m_margin.value;
            break;
        }
        case zofia::Margin::RIGHT: {
            xPosition -= context.m_margin.value;
            break;
        }
        default: {
            xPosition = 0;
            yPosition = 0;
            break;
        }
    }

    this->m_position = context.m_position;
    this->m_sprite.setOrigin(context.m_origin.getXAxis(), context.m_origin.getYAxis());
    this->m_sprite.setPosition(context.m_position.getXAxis() + xPosition,
                               context.m_position.getYAxis() + yPosition);
}

template<typename E>
zofia::RectangleContext zofia::Rectangle::cast(E &context) {
    return static_cast<RectangleContext>(context);
}

#endif