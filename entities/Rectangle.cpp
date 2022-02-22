//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_RECT_CPP__
#define ZOFIA_RECT_CPP__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../core/Size.cpp"
#include "../core/Position.cpp"
#include "../core/Util.cpp"

#include "../include/entities/base.hpp"

#define ZOFIA zofia::

namespace zofia {
    class RectangleContext : public EntityContext {
        public:
          Size m_size;
          Position m_position;
          Position m_origin;
          sf::Color m_color;


          explicit RectangleContext(Size &size, Position &position, sf::Color &color)
                  : m_size(size), m_position(position), m_color(color) {}

          explicit RectangleContext(Size &size, Position &position) : m_size(size), m_position(position) {}

          explicit RectangleContext() = default;

          virtual ~RectangleContext() = default;

          Size getSize() const {
              return this->m_size;
          }

          Position getPosition() const {
              return this->m_position;
          }

          sf::Color getColor() const {
              return this->m_color;
          }

          Position getOrigin() const{
              return this->m_origin;
          }
    };

    class Rectangle : public Entity {
        private:
          sf::Texture m_texture;
          sf::Sprite m_sprite;
          Size m_size;
          Position m_position;

          sf::Texture createTexture(std::string path);

          template<typename E>
          RectangleContext cast(E &context);

        public:
          explicit Rectangle(sf::RenderWindow &window, const std::string &pathBackground, const Size &size,
                             const Position &startPosition)
                  : m_size(size),
                    m_position(startPosition), Entity(window) {
              this->m_texture = createTexture(pathBackground);
              this->m_sprite.setTexture(this->m_texture);
          }

          explicit Rectangle(sf::RenderWindow &window, const Size &size, const Position &startPosition)
                  : m_size(size),
                    m_position(startPosition), Entity(window) {
              this->m_texture.create(size.getWidth(), size.getHeight());
              this->m_sprite.setTexture(this->m_texture);
          }

          virtual ~Rectangle() = default;

          void draw() override;

          template<typename E>
          void update(E &context);

          Size getSize() const {
              return this->m_size;
          }

          Position getPosition() const {
              return this->m_position;
          }

          sf::Color getColor() const {
              return this->m_sprite.getColor();
          }

          sf::FloatRect getLocalBounds() const {
              return this->m_sprite.getLocalBounds();
          }

          sf::FloatRect getGlobalBounds() const {
              return this->m_sprite.getGlobalBounds();
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

void zofia::Rectangle::draw() {
    this->m_window.draw(this->m_sprite);
}

template<typename E>
void zofia::Rectangle::update(E &c) {
    RectangleContext context = cast(c);

    this->m_position = context.m_position;
    this->m_sprite.setOrigin(context.m_origin.getXAxis(), context.m_origin.getYAxis());
    this->m_sprite.setPosition(context.m_position.getXAxis(), context.m_position.getYAxis());
}

template<typename E>
zofia::RectangleContext zofia::Rectangle::cast(E &context) {
    return static_cast<RectangleContext>(context);
}

#endif