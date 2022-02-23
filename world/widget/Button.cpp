//
// Created by kienle on 18/02/2022.
//

#ifndef ZOFIA_BUTTON_CPP
#define ZOFIA_BUTTON_CPP

#include "../util/Align.cpp"
#include "../Typography.cpp"
#include "../Rectangle.cpp"

#include "BaseView.cpp"
#include "BaseViewContext.cpp"

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
          explicit Button(std::string str, Position position, Size size) : BaseView<ButtonContext>("button") {
              this->addEntity("typo", zofia::make_unique<Typography>());
              this->addEntity("rect", zofia::make_unique<Rectangle>("resources/views/button.jpg", size, position));

              setText(str);
          };

          void setText(std::string &str);

          void center(Rectangle &rect);

          void draw(sf::RenderTarget &target) override;

          void update(ButtonContext &context) override;

          void alignText(zofia::Align align);

          Position getPosition() {
              return this->getRectangle()->getPosition();
          }

          Size getSize() {
              return this->getRectangle()->getSize();
          }

          void margin(MarginInfo marginInfo);
    };
}

void zofia::Button::draw(sf::RenderTarget &target) {
    getRectangle()->draw(target);
    getTypography()->draw(target);
}

void zofia::Button::update(ButtonContext &context) {

}

void zofia::Button::setText(std::string &str) {
    TypographyContext typographyContext(str);
    getTypography()->update(typographyContext);
}

void zofia::Button::center(Rectangle &rect) {
    Size sizeRect = rect.getSize();

    sf::FloatRect internalRect = getRectangle()->getLocalBounds();

    RectangleContext context;

    context.m_origin = Position(internalRect.width / 2, 0.0f);
    context.m_position = Position(sizeRect.getWidth() / 2, sizeRect.getHeight() / 2);

    getRectangle()->update(context);
}

void zofia::Button::alignText(zofia::Align align) {
    auto typoGLB = getTypography()->getGlobalBounds();
    auto rectBtn = getRectangle();
//    auto rectLB = getRectangle()->getGlobalBounds();

    TypographyContext context;

    //Must set position rectBtn before set position typo
    if (align == zofia::Align::LEFT) {
        context.m_origin = Position(typoGLB.width / 2, typoGLB.height / 2.5);
        context.m_position = Position(rectBtn->getPosition().getXAxis(), rectBtn->getPosition().getYAxis());
    } else if (align == zofia::Align::CENTER) {
        auto textGB = getTypography()->getGlobalBounds();
        context.m_origin = Position(textGB.width / 2, textGB.height / 2 * -1);
        context.m_position = Position(rectBtn->getPosition().getXAxis(), rectBtn->getPosition().getYAxis());
    } else if (align == zofia::Align::RIGHT) {
        context.m_origin = Position(typoGLB.width / 2, typoGLB.height / 2);
        context.m_position = Position(rectBtn->getPosition().getXAxis(), rectBtn->getPosition().getYAxis());
    } else {
        //Default center
        context.m_origin = Position();
        context.m_position = Position();
    }
    getTypography()->update(context);
}

void zofia::Button::margin(zofia::MarginInfo marginInfo) {
    sf::FloatRect internalRect = getRectangle()->getLocalBounds();


    RectangleContext context;
    Position position = getRectangle()->getPosition();
    context.m_origin = Position(internalRect.width / 2, 0.0f);

    float value = marginInfo.usePlus() ? marginInfo.value : (marginInfo.value) * -1;
    if (marginInfo.type == Margin::TOP || marginInfo.type == Margin::BOTTOM) {
        context.m_position = Position(position.getXAxis(), position.getYAxis() + value);
    } else if (marginInfo.type == Margin::LEFT || marginInfo.type == Margin::RIGHT) {
        context.m_position = Position(position.getXAxis() + value, position.getYAxis());
    }

    getRectangle()->update(context);
}

zofia::Typography *zofia::Button::getTypography() {
    return dynamic_cast<Typography *>(m_entities["typo"].get());
}

zofia::Rectangle *zofia::Button::getRectangle() {
    return dynamic_cast<Rectangle *>(m_entities["rect"].get());
}

#endif