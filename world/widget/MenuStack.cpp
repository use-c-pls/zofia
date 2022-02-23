//
// Created by kienle on 23/02/2022.
//
#ifndef ZOFIA_MENU_STACK_CPP__
#define ZOFIA_MENU_STACK_CPP__

#include <SFML/Graphics.hpp>
#include <utility>

#include "BaseViewContext.cpp"
#include "BaseView.cpp"
#include "Button.cpp"

namespace zofia {
    class MenuStackContext : BaseViewContext {

    };

    class MenuStack : public BaseView<MenuStackContext> {
        private:
          zofia::Button *getButton(const std::string &name) {
              return dynamic_cast<Button *>(m_entities[name].get());
          }

        public:
          MenuStack() : BaseView("menu_stack") {
              this->addEntity("start", std::move(zofia::make_unique<Button>("Start", Position(0, 0), Size(302, 76))));
              this->addEntity("setting",
                              std::move(zofia::make_unique<Button>("Setting", Position(0, 0), Size(302, 76))));
              this->addEntity("quit", std::move(zofia::make_unique<Button>("Quit", Position(0, 0), Size(302, 76))));

              getButton("start")->setId("start_btn");
              getButton("setting")->setId("setting_btn");
              getButton("quit")->setId("quit_btn");
          }

          void handleEvent(sf::RenderTarget &target, sf::Event e);

          void center(Rectangle &rect);

          void setFunc(const std::string &name, std::function<void(void)> func);

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

void zofia::MenuStack::setFunc(const std::string &name, std::function<void(void)> func) {
    this->getButton(name)->setFunc(std::move(func));
}

void zofia::MenuStack::handleEvent(sf::RenderTarget &target, sf::Event e) {
    for (auto &it: m_entities) {
        getButton(it.first)->handleEvent(target, e);
    }
}

void zofia::MenuStack::update(zofia::MenuStackContext &context) {

}

void zofia::MenuStack::draw(sf::RenderTarget &target) {
    for (auto &it: m_entities) {
        getButton(it.first)->draw(target);
    }
}

#endif