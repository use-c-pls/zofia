//
// Created by kienle on 23/02/2022.
//
#ifndef ZOFIA_MENU_STACK_CPP__
#define ZOFIA_MENU_STACK_CPP__

#include <SFML/Graphics.hpp>

#include "BaseViewContext.cpp"
#include "BaseView.cpp"
#include "Button.cpp"

namespace zofia {
    class MenuStackContext : BaseViewContext {

    };

    class MenuStack : public BaseView<MenuStackContext> {
        private:
          zofia::Button *cast(std::unique_ptr<DrawableEntity> entity) {
              return dynamic_cast<Button *>(entity.get());
          }

          zofia::Button *getButton(std::string name) {
              return cast(std::move(m_entities[name]));
          }

        public:
          MenuStack() : BaseView() {
              this->addEntity("start", std::move(zofia::make_unique<Button>("Start", Position(0, 0), Size(302, 76))));
              this->addEntity("setting", std::move(zofia::make_unique<Button>("Setting", Position(0, 0), Size(302, 76))));
              this->addEntity("quit", std::move(zofia::make_unique<Button>("Quit", Position(0, 0), Size(302, 76))));

          }

          void handleEvent(sf::RenderTarget &target, sf::Event e);

          void center(Rectangle &rect);

          void setFunc(std::string name, std::function<void(void)> func);

          void draw(sf::RenderTarget &target) override;

          void update(MenuStackContext &context) override;
    };
}

void zofia::MenuStack::center(Rectangle &rect) {
    auto startBtn = this->getButton("start");
    auto settingBtn = this->getButton("setting");
    auto quitBtn = this->getButton("quit");

    startBtn->center(rect);
    settingBtn->center(rect);
    quitBtn->center(rect);

    startBtn->margin(zofia::MarginInfo(Margin::BOTTOM, 200));
    settingBtn->margin(zofia::MarginInfo(Margin::BOTTOM, 100));

    startBtn->alignText(zofia::Align::CENTER);
    settingBtn->alignText(zofia::Align::CENTER);
    quitBtn->alignText(zofia::Align::CENTER);
}

void zofia::MenuStack::setFunc(std::string name, std::function<void(void)> func) {
    this->getButton(name)->setFunc(func);
}

void zofia::MenuStack::handleEvent(sf::RenderTarget &target, sf::Event e) {
    for (auto & it : m_entities) {
        cast(std::move(it.second))->handleEvent(target, e);
    }
}

void zofia::MenuStack::update(zofia::MenuStackContext &context) {

}

void zofia::MenuStack::draw(sf::RenderTarget &target) {
//    for (auto & it : m_entities) {
//
//    }
    getButton("start")->draw(target);
}

#endif