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

          int m_marginTop;
          int m_marginBottom;
          int m_marginLeft;
          int m_marginRight;

        public:
          explicit Button(sf::RenderWindow &window, std::string str, Position position, Size size)
                  : BaseView<ButtonContext>("button") {
              auto *typography = new Typography(window);
              auto *rectangle = new Rectangle(window,"resources/views/button.jpg", size, position);
              this->addEntity("typo",typography);
              this->addEntity("rect",rectangle);

              setText(str);
          };

          virtual ~Button() = default;

          void setText(std::string &str);

          void center(Rectangle &rect);

          void draw() override;

          void update(ButtonContext &context) override;

          Position getPosition(){
              return this->getRectangle()->getPosition();
          }

          Size getSize(){
              return this->getRectangle()->getSize();
          }

          void alignText(int constant);

          void marginTop(int num);

          void marginBottom(int num);

          void marginLeft(int num);

          void marginRight(int num);
    };
}

void zofia::Button::draw() {
    getRectangle()->draw();
    getTypography()->draw();
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
    Size sizeRect = rect.getSize();

    sf::FloatRect internalRect = getRectangle()->getLocalBounds();

    RectangleContext context;

    context.m_origin = Position(internalRect.width / 2, 0.0f);
    context.m_position = Position(sizeRect.getWidth()/ 2,sizeRect.getHeight()/2);

    getRectangle()->update(context);
}

void zofia::Button::alignText(int constant){
    auto typoGLB = getTypography()->getGlobalBounds();
    auto rectBtn = getRectangle();
//    auto rectLB = getRectangle()->getGlobalBounds();

    TypographyContext context;

    //Must set position rectBtn before set position typo
    if(constant == zofia::LEFT_TEXT){
        context.m_origin = Position(typoGLB.width/2,typoGLB.height/2.5);
        context.m_position = Position(rectBtn->getPosition().getXAxis(),rectBtn->getPosition().getYAxis());
    }else if(constant == zofia::CENTER_TEXT){
        auto textLB = getTypography()->getLocalBounds();
        auto textGB =  getTypography()->getGlobalBounds();
        context.m_origin = Position(textGB.width / 2, textGB.height / 2 * -1);
        context.m_position = Position(rectBtn->getPosition().getXAxis(), rectBtn->getPosition().getYAxis());
    }else if(constant == zofia::RIGHT_TEXT){
        context.m_origin = Position(typoGLB.width/2,typoGLB.height/2);
        context.m_position = Position(rectBtn->getPosition().getXAxis(),rectBtn->getPosition().getYAxis());
    }else{
        //Default center
        context.m_origin = Position();
        context.m_position = Position();
    }
    getTypography()->update(context);
}

void zofia::Button::marginTop(int num) {
    sf::FloatRect internalRect = getRectangle()->getLocalBounds();

    RectangleContext context;
    Position position = getRectangle()->getPosition();
    context.m_origin = Position(internalRect.width/2, 0.0f);
    context.m_position = Position(position.getXAxis(),position.getYAxis()+num);

    getRectangle()->update(context);
}

void zofia::Button::marginBottom(int num) {
    sf::FloatRect internalRect = getRectangle()->getLocalBounds();

    RectangleContext context;
    Position position = getRectangle()->getPosition();
    context.m_origin = Position(internalRect.width/2, 0.0f);
    context.m_position = Position(position.getXAxis(),position.getYAxis()-num);

    getRectangle()->update(context);
}

void zofia::Button::marginLeft(int num) {

}

void zofia::Button::marginRight(int num) {

}

#endif