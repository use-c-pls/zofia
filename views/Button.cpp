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

          sf::Color getColor() const{
              return this->m_color;
          }

    };

    class Button : public BaseView<ButtonContext> {
        private:
          Typography m_typo;
          Rectangle m_rect;
        public:


          explicit Button(sf::RenderWindow &window,std::string text,Position position,Size size) : BaseView<ButtonContext>(){
              Typography typography(window);
              Rectangle rectangle(window,size,position);
              this->addEntity(typography);
              this->addEntity(rectangle);
          };

          virtual ~Button() = default;

          void setText(Typography &typo);

          void setText(std::string &str);


          void draw() override;

          void update(ButtonContext &context) override;
    };
}

void zofia::Button::draw() {
    this->m_rect.draw();

}

void zofia::Button::update(ButtonContext &context) {
    //setIntData(m_typo,);
    RectangleContext rectContext(context.)
    this->m_rect.update()
}

template<typename T>
void zofia::Button::setIntData(T &var, int data) {
    if (data > 0) {//constraint
        var = data;
    }
    //Do nothing
}

template<typename T>
void zofia::Button::setStringData(T &var, std::string data) {
    if (data.length() > 0) {
        var = data;
    }
    //do nothing
}
//
//void zofia::Button::setText(std::string &str) {
//    TypographyContext context(str);
//    m_typo.update(context);
//}
//
//void zofia::Button::setText(Typography &typo) {
//    TypographyContext context(typo.getText().getString());
//    m_typo.update(context);
//}

#endif