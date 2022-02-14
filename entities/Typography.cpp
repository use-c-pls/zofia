//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_TPG_CPP__
#define ZOFIA_TPG_CPP__

#include "../config/Config.cpp"
#include "../logging/logging.hpp"
#include "Entity.cpp"

#define ZOFIA zofia::
namespace zofia {
    class Typography : public Entity {
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
          ~Typography();
          void draw() override;
          void updateText(const std::string &text);
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

void zofia::Typography::updateText(const std::string &text) {
    m_text.setString(text);
}

#endif