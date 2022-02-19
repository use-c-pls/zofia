//
// Created by kienle on 18/02/2022.
//

#ifndef ZOFIA_BUTTON_CPP
#define ZOFIA_BUTTON_CPP

#include "../entities/full.hpp"
#include "base.hpp"

namespace zofia {
    class ButtonContext : public BaseViewContext {
        private:
          std::string m_str;
          sf::Color m_color;
          Position m_position;
          Size m_size;
        public:
          std::string getText() const {
              return this->m_str;
          }

          sf::Color getColor() const {
              return this->m_color;
          }

    };

    class Button : public BaseView<ButtonContext> {
        private:
          Typography *getTypography();

          Rectangle *getRectangle();

        public:
          explicit Button(sf::RenderWindow &window, std::string str, Position position, Size size)
                  : BaseView<ButtonContext>("button") {
              auto *typography = new Typography(window);
              auto *rectangle = new Rectangle(window, size, position);
              this->addEntity(typography);
              this->addEntity(rectangle);

              setText(str);
          };

          virtual ~Button() = default;

          void setText(std::string &str);

          void draw() override;

          void update(ButtonContext &context) override;
    };
}

void zofia::Button::draw() {
    TypographyContext context("newStr");

    this->getTypography()->update(context);
}

zofia::Typography *zofia::Button::getTypography() {
    return dynamic_cast<Typography *>(m_entities[0]);
}

zofia::Rectangle *zofia::Button::getRectangle() {
    return dynamic_cast<Rectangle *>(m_entities[1]);
}

void zofia::Button::update(ButtonContext &context) {

}

void zofia::Button::setText(std::string &str) {
    TypographyContext typographyContext(str);
    getTypography()->update(typographyContext);
}

#endif