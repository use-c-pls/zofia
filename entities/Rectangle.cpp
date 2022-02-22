//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_RECT_CPP__
#define ZOFIA_RECT_CPP__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../include/core/core.hpp"
#include "../include/entities/base.hpp"

#define ZOFIA zofia::

namespace zofia {
    class RectangleContext : public EntityContext {
        public:
          Size m_size;
          Position m_position;
          Position m_origin;
          sf::Color m_color;
          int m_marginTop{0};
          int m_marginBottom{0};
          int m_marginLeft{0};
          int m_marginRight{0};
        public:
          int getMarginTop() const {
              return m_marginTop;
          }

          int getMarginBottom() const {
              return m_marginBottom;
          }

          int getMarginLeft() const {
              return m_marginLeft;
          }

          int getMarginRight() const {
              return m_marginRight;
          }

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

          sf::Color getColor() {
              return this->m_color;
          }

          Position getOrigin(){
              return this->m_origin;
          }
    };

    class Rectangle : public Entity {
        public:
          sf::Texture &getTexture();

          sf::Sprite &getSprite();

          Size &getSize();

          Position &getPosition();

          sf::FloatRect &getRect();

        private:
          sf::Texture m_texture;
          sf::Sprite m_sprite;
          Size m_size;
          Position m_position;
          int m_marginTop{0};
          int m_marginBottom{0};
          int m_marginLeft{0};
          int m_marginRight{0};

          sf::Texture createTexture(std::string path);

          template<typename E>
          RectangleContext cast(E &context);

        public:
          explicit Rectangle(sf::RenderWindow &window, const std::string &pathBackground, const Size &size,
                             const Position &startPosition)
                  : m_size(size),
                    m_position(startPosition), Entity(window) {
              this->m_texture = createTexture(pathBackground);//tie texture to rect in createTexture
              this->m_sprite.setTexture(this->m_texture);//tie rect to sprite
              this->m_sprite.setPosition(startPosition.getXAxis(),startPosition.getYAxis());
          }

          explicit Rectangle(sf::RenderWindow &window, const Size &size, const Position &startPosition)
                  : m_size(size),
                    m_position(startPosition), Entity(window) {
              this->m_texture.create(size.getWidth(), size.getHeight());
                            this->m_sprite.setTexture(this->m_texture);//tie rect to sprite
                            this->m_sprite.setPosition(startPosition.getXAxis(),startPosition.getYAxis());
          }

          virtual ~Rectangle() = default;

          void draw() override;

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

          sf::Vector2f getOrigin(){
              return this->m_sprite.getOrigin();
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

    int xPosition = 0;
    int yPosition = 0;
    if(context.m_marginTop != 0){
        yPosition += context.m_marginTop;
        m_marginTop = context.m_marginTop;
    }
    if(context.m_marginBottom != 0){
        yPosition -= context.m_marginBottom;
        m_marginBottom = context.m_marginBottom;
    }
    if(context.m_marginLeft!=0) {
        xPosition -= context.m_marginLeft;
        m_marginLeft = context.m_marginLeft;
    }
    if(context.m_marginRight != 0){
        xPosition += context.m_marginRight;
        m_marginRight = context.m_marginRight;
    }
    this->m_position = context.getPosition();
    this->m_sprite.setOrigin(context.getOrigin().getXAxis(),context.getOrigin().getYAxis());
    this->m_sprite.setPosition(context.getPosition().getXAxis()+xPosition,context.getPosition().getYAxis()+yPosition);

}

template<typename E>
zofia::RectangleContext zofia::Rectangle::cast(E &context) {
    return static_cast<RectangleContext>(context);
}

sf::Texture &zofia::Rectangle::getTexture() {
    return m_texture;
}

sf::Sprite &zofia::Rectangle::getSprite() {
    return m_sprite;
}

zofia::Size &zofia::Rectangle::getSize() {
    return m_size;
}

zofia::Position &zofia::Rectangle::getPosition() {
    return m_position;
}

#endif