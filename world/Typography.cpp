//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_TPG_CPP__
#define ZOFIA_TPG_CPP__

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "../include/core/resources.hpp"
#include "../include/core/config.hpp"
#include "../include/core/core.hpp"

#include "DrawableEntity.cpp"
#include "EntityContext.cpp"

namespace zofia {
    class TypographyContext : public EntityContext {
        public:
          std::string m_text;
          int m_textSize{};
          Position m_position;
          sf::Color m_color{sf::Color::Black};
          Position m_origin;

          explicit TypographyContext(std::string text, int textSize) : m_text(std::move(text)), m_textSize(textSize) {}

          explicit TypographyContext() = default;

          explicit TypographyContext(std::string text) : m_text(std::move(text)) {}

          explicit TypographyContext(int textSize) : m_textSize(textSize) {}
    };

    class Typography : public DrawableEntity {
        private:
          sf::Text m_text;
          sf::Font m_font;
          Position m_position;

          template<typename E>
          TypographyContext cast(E &context);

        public:

          explicit Typography() : DrawableEntity() {
              this->m_font = ResourceHolder::get().fonts().get(DEFAULT_FONT);
              this->m_text = createText("");
          }

          explicit Typography(const std::string &text, std::string &fontName) : DrawableEntity() {
              this->m_font = ResourceHolder::get().fonts().get(fontName);
              this->m_text = createText(text);
          }

          void draw(sf::RenderTarget &target) override;

          template<typename E>
          void update(E &context);

          sf::FloatRect getLocalBounds() const {
              return this->m_text.getLocalBounds();
          }

          sf::FloatRect getGlobalBounds() const {
              return this->m_text.getGlobalBounds();
          }

          Position getPosition() {
              return this->m_position;
          }

        private:
          sf::Text createText(const std::string &message);
    };
}

template<typename E>
void zofia::Typography::update(E &context) {
    TypographyContext casted = cast(context);

    if (casted.m_textSize != 0) {
        this->m_text.setCharacterSize(casted.m_textSize);
    }
    if (casted.m_text.length() != 0) {
        this->m_text.setString(casted.m_text);
    }

    if (casted.m_color != this->m_text.getFillColor()) {
        this->m_text.setFillColor(casted.m_color);
    }
    this->m_position = Position(casted.m_position.getXAxis(), casted.m_position.getYAxis());
    this->m_text.setOrigin(casted.m_origin.getXAxis(), casted.m_origin.getYAxis());
    this->m_text.setPosition(casted.m_position.getXAxis(), casted.m_position.getYAxis());
}

void zofia::Typography::draw(sf::RenderTarget &target) {
    target.draw(this->m_text);
}

sf::Text zofia::Typography::createText(const std::string &message) {
    sf::Text text;
    Position position{0, 0};
    text.setString(message);
    text.setCharacterSize(36); // in pixels, not points!
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setFont(m_font);
    text.setPosition(position.getXAxis(), position.getYAxis());
    return text;
}

template<typename E>
zofia::TypographyContext zofia::Typography::cast(E &context) {
    return static_cast<TypographyContext>(context);
}

#endif