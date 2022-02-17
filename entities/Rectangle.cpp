//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_RECT_CPP__
#define ZOFIA_RECT_CPP__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../core/Size.cpp"
#include "../core/Position.cpp"
#include "../core/logging/logging.hpp"

#include "../entities/base.hpp"

#define ZOFIA zofia::

namespace zofia {
    class RectangleContext : public EntityContext {
        public:
          Size m_size;
          Position m_position;

          explicit RectangleContext(Size &size, Position &position) : m_size(size), m_position(position) {}

          virtual ~RectangleContext() = default;
    };

    class Rectangle : public Entity<RectangleContext> {
        private:
          sf::Texture m_texture;
          sf::Sprite m_sprite;
          Size m_size;
          Position m_position;
          sf::IntRect m_rect;

          sf::Texture createTexture(std::string path);

        public:

          explicit Rectangle(sf::RenderWindow &window, const std::string &path, const Size &size,
                             const Position &startPosition)
                  : m_size(size),
                    m_rect(startPosition.getXAxis(), startPosition.getYAxis(), size.getWidth(), size.getHeight()),
                    m_position(startPosition), Entity(window) {
              this->m_texture = createTexture(path);//tie texture to rect in createTexture
              this->m_sprite.setTexture(this->m_texture);//tie rect to sprite
          }

          Rectangle(sf::RenderWindow &window, const std::string &path,
                    const int &width, const int &height,
                    const int &x, const int &y)
                  : Rectangle(window, path, Size(width, height), Position(x, y)) {}

          virtual ~Rectangle() = default;

          void draw() override;

          void update(RectangleContext &context) override;


          Size getSize() const {
              return this->m_size;
          }

          Position getPosition() const {
              return this->m_position;
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

void zofia::Rectangle::update(RectangleContext &context) {

}

#endif