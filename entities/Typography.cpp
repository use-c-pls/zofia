//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_TPG_CPP__
#define ZOFIA_TPG_CPP__

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "../include/core/config.hpp"
#include "../include/core/logging.hpp"

#include "Entity.cpp"
#include "EntityContext.cpp"

#define ZOFIA zofia::
namespace zofia {
    class TypographyContext : public EntityContext {
        public:
          std::string m_text;
          int m_textSize{};

          explicit TypographyContext(std::string text, int textSize) : m_text(std::move(text)), m_textSize(textSize) {}

          explicit TypographyContext() = default;

          explicit TypographyContext(std::string text) : m_text(std::move(text)) {}

          explicit TypographyContext(int textSize) : m_textSize(textSize) {}

          virtual ~TypographyContext() = default;
    };

    class Typography : public Entity {
        private:
          sf::Text m_text;
          sf::Font m_font;

          template<typename E>
          TypographyContext cast(E &context);

        public:
          explicit Typography(sf::RenderWindow &window, std::string &fontPath) : Entity(window) {
              this->initFont(fontPath);
              this->m_text = createText("");
          };

          explicit Typography(sf::RenderWindow &window) : Entity(window) {
              this->initFont(DEFAULT_FONT_PATH);
              this->m_text = createText("");
          }

          virtual ~Typography();

          void draw() override;

          template<typename E>
          void update(E &context);

        private:
          sf::Text createText(const std::string &message);

          void initFont(std::string fontPath);

    };
}

template<typename E>
void zofia::Typography::update(E &context) {
    TypographyContext casted = cast(context);

    LOG_DEBUG(casted.m_text);
}

zofia::Typography::~Typography() {
    LOG_INFO("Destroying Typography...");
}

void zofia::Typography::draw() {
    this->m_window.draw(this->m_text);
}

sf::Text zofia::Typography::createText(const std::string &message) {
    sf::Text text;
    text.setString(message);
    text.setCharacterSize(56); // in pixels, not points!
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setFont(m_font);
    return text;
}

void zofia::Typography::initFont(std::string fontPath) {
    if (!m_font.loadFromFile(fontPath)) {
        LOG_ERROR("Not found any font at `{}`", fontPath);
    }
}

template<typename E>
zofia::TypographyContext zofia::Typography::cast(E &context) {
    return static_cast<TypographyContext>(context);
}

#endif