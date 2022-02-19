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

#include "../entities/base.hpp"

#define ZOFIA zofia::

namespace zofia {
    class RectangleContext : public EntityContext {
        public:
          Size m_size;
          Position m_position;
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
    };

    class Rectangle : public Entity {
        private:
          sf::Texture m_texture;
          sf::Sprite m_sprite;
          Size m_size;
          Position m_position;
          sf::IntRect m_rect;

          sf::Texture createTexture(std::string path);

          template<typename E>
          RectangleContext cast(E &context);

        public:

          explicit Rectangle(sf::RenderWindow &window, const std::string &path, const Size &size,
                             const Position &startPosition)
                  : m_size(size),
                    m_rect(startPosition.getXAxis(), startPosition.getYAxis(), size.getWidth(), size.getHeight()),
                    m_position(startPosition), Entity(window) {
              this->m_texture = createTexture(path);//tie texture to rect in createTexture
              this->m_sprite.setTexture(this->m_texture);//tie rect to sprite
          }

          explicit Rectangle(sf::RenderWindow &window, const Size &size,
                             const Position &startPosition)
                  : m_size(size),
                    m_rect(startPosition.getXAxis(), startPosition.getYAxis(), size.getWidth(), size.getHeight()),
                    m_position(startPosition), Entity(window) {
              this->m_texture.create(size.getWidth(), size.getHeight());
              this->m_sprite.setTexture(this->m_texture);//tie rect to sprite
          }

          Rectangle(sf::RenderWindow &window, const std::string &path,
                    const int &width, const int &height,
                    const int &x, const int &y)
                  : Rectangle(window, path, Size(width, height), Position(x, y)) {}

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
    };
}

sf::Texture zofia::Rectangle::createTexture(std::string path) {
    sf::Texture texture{};

    sf::Clock clock;//start time
    clock.restart();

    if (!texture.loadFromFile(path, this->m_rect)) {
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
    if (m_sprite.getColor() != context.getColor()) {
        this->m_sprite.setColor(context.getColor());
    }
    if (this->m_rect.width != context.getSize().getWidth()) {
        this->m_rect.width = context.getSize().getWidth();
    }
    if (this->m_rect.height != context.getSize().getHeight()) {
        this->m_rect.height = context.getSize().getHeight();
    }
    if (this->m_rect.left != context.getPosition().getXAxis()) {
        this->m_rect.left = context.getPosition().getXAxis();
    }
    if (this->m_rect.top != context.getPosition().getYAxis()) {
        this->m_rect.top = context.getPosition().getYAxis();
    }
}

template<typename E>
zofia::RectangleContext zofia::Rectangle::cast(E &context) {
    return static_cast<RectangleContext>(context);
}

#endif