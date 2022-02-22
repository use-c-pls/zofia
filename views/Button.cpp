//
// Created by kienle on 18/02/2022.
//

#ifndef ZOFIA_BUTTON_CPP
#define ZOFIA_BUTTON_CPP

#include "../include/entities/full.hpp"
#include "../include/views/base.hpp"

namespace zofia {
    class ButtonContext : public BaseViewContext {
        public:
          std::string m_str;
          sf::Color m_color;
          Position m_position;
          Size m_size;
    };

    class Button : public BaseView<ButtonContext> {
        private:
          Typography *getTypography();

          Rectangle *getRectangle();

        public:
          explicit Button(sf::RenderWindow &window, std::string str, Position position, Size size)
                  : BaseView<ButtonContext>("button") {
              auto *typography = new Typography(window);
              auto *rectangle = new Rectangle(window, "resources/views/button.png", size, position);

              this->addEntity("typo", typography);
              this->addEntity("rect", rectangle);

              setText(str);
          };

          virtual ~Button() = default;

          void setText(std::string &str);

          void center(Rectangle &rect);

          void draw() override;

          void update(ButtonContext &context) override;
    };
}

void zofia::Button::draw() {
    getTypography()->draw();
    getRectangle()->draw();
}

zofia::Typography *zofia::Button::getTypography() {
    return dynamic_cast<Typography *>(m_entities["typo"]);
}

zofia::Rectangle *zofia::Button::getRectangle() {
    return dynamic_cast<Rectangle *>(m_entities["rect"]);
}

void zofia::Button::update(ButtonContext &context) {

}

void zofia::Button::setText(std::string &str) {
    TypographyContext typographyContext(str);
    getTypography()->update(typographyContext);
}

void zofia::Button::center(Rectangle &rect) {
    Position posRect = rect.getPosition();
    Size sizeRect = rect.getSize();

    sf::FloatRect internalRect = getRectangle()->getLocalBounds();

    RectangleContext context;
    context.m_origin = Position(internalRect.width / 2, internalRect.height / 2);
    context.m_position = Position(sizeRect.getWidth() / 2, sizeRect.getHeight() / 2);

    getRectangle()->update(context);
}

#endif