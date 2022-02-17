//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_TPG_CPP__
#define ZOFIA_TPG_CPP__

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "../core/config/config.hpp"
#include "../core/logging/logging.hpp"

#include "Entity.cpp"
#include "EntityContext.cpp"

#define ZOFIA zofia::
namespace zofia {
    class TypographyContext : public EntityContext {
        public:
          std::string m_text;
          int m_textSize;

          explicit TypographyContext(std::string text, int textSize) : m_text(text), m_textSize(textSize) {}

          virtual ~TypographyContext() = default;


    };

    class Typography : public Entity<TypographyContext> {
        private:
          sf::Text m_text;
          sf::Font m_font;
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

          void update(TypographyContext &context) override;

        private:
          sf::Text createText(const std::string &message);

          void initFont(std::string fontPath);
    };
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

void zofia::Typography::update(TypographyContext &context) {
    this->m_text.setString(context.m_text);
    this->m_text.setCharacterSize(context.m_textSize);
}

#endif