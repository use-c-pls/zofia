/* Author @daoluke */
#ifndef ZOFIA_HITBOX_OBJECT_CPP
#define ZOFIA_HITBOX_OBJECT_CPP

#include "../include/core/logging.hpp"
#include "DrawableObject.cpp"

namespace zofia {

    struct HitBoxData {
        int16_t w;
        int16_t h;
        int16_t xOff;
        int16_t yOff;


        HitBoxData(int16_t w, int16_t h, int16_t xOff = 0, int16_t yOff = 0) {
            this->w = w;
            this->h = h;
            this->xOff = xOff;
            this->yOff = yOff;
        }

        HitBoxData() : HitBoxData(0, 0) {}
    };

    class HitBoxObject : public DrawableObject<sf::RectangleShape> {
        private:
          sf::RectangleShape m_rect;
          HitBoxData m_data{};
        public:
          HitBoxObject() {
              init();
          }

          explicit HitBoxObject(const HitBoxData &data) : m_data(data) {
              init();
          }

          HitBoxObject(int w, int h) : HitBoxObject(HitBoxData(w, h)) {
          }

          explicit HitBoxObject(std::vector<int16_t> v) : HitBoxObject(HitBoxData(v[0], v[1], v[2], v[3])) {}

          sf::FloatRect getLocalBound() {
              return m_rect.getLocalBounds();
          }

          sf::FloatRect getGlobalBound() {
              return m_rect.getGlobalBounds();
          }

          void setOrigin(float x, float y) {
              m_rect.setOrigin(x, y);
          }

          void setColor(sf::Color color) {
              m_rect.setOutlineColor(color);
          }

          bool isHit(HitBoxObject another) {
              return m_rect.getGlobalBounds().intersects(another.getGlobalBound());
          }

          void setPosition(const Position &pos);

          void setPosition(float x, float y);

          void setHitBoxSize(int16_t width, int16_t height);

          sf::RectangleShape getDrawableObject() override {
              return this->m_rect;
          }

          float getXPos() const {
              return m_position.getXAxis();
          }

          float getYPos() const {
              return m_position.getYAxis();
          }

          int16_t getWidth() {
              return m_data.w;
          }

          int16_t getHeight() {
              return m_data.h;
          }

          void reset() {
              init();
          }

          void init() {
              m_rect.setFillColor(sf::Color::Transparent);
              m_rect.setOutlineColor(sf::Color::Red);
              m_rect.setOutlineThickness(3);
              m_rect.setSize(sf::Vector2f(m_data.w, m_data.h));
          }
    };

    void HitBoxObject::setPosition(const Position &pos) {
        float x = pos.getXAxis();
        float y = pos.getYAxis();

        m_position.setXAxis(x);
        m_position.setYAxis(y);

        m_rect.setPosition(x + m_data.xOff, y + m_data.yOff);
    }

    void HitBoxObject::setPosition(float x, float y) {
        setPosition(Position(sf::Vector2f{x, y}));
    }

    void HitBoxObject::setHitBoxSize(int16_t width, int16_t height) {
        m_rect.setSize(sf::Vector2f(width, height));
    }
}

#endif