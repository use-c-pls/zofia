//
// Created by kienle on 14/02/2022.
//
#ifndef ZOFIA_TPG_CPP__
#define ZOFIA_TPG_CPP__
#include "Entity.cpp"

#define ZOFIA zofia::
namespace zofia {
    class Typography : public Entity{
        private:
            sf::Text m_text{};
        public:
            explicit Typography(sf::RenderWindow& window) : Entity(window){
                this->init();
            }
            explicit Typography(sf::RenderWindow& window,const std::string& fontPath) : Entity(window){
                this->init();
                //setFontFromStream(fontPath);
            }
            ~Typography();
            void draw() ;
            void init() ;//override;
            sf::Text getText(){
                return this->m_text;
            }
            void setFontFromStream(const std::string& path);
    };
}

void zofia::Typography::init(){
    //Nothing to initialize
    this->m_text.setString("cac");
    this->m_text.setCharacterSize(56); // in pixels, not points!
    this->m_text.setFillColor(sf::Color::Red);
    this->m_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::Font font;
    font.loadFromFile("resources/fonts/arial.ttf");
    this->m_text.setFont(font);

}

zofia::Typography::~Typography() {}

void zofia::Typography::setFontFromStream(const std::string& path) {
    /*sf::FileInputStream stream;
    stream.open(path);*/
    sf::Font font;
    if(!font.loadFromFile(path)){
        //Couldn't load from the path check path exist or not
    }else{
        this->m_text.setFont(font);
    }
}

void zofia::Typography::draw(){
    /*sf::Text text;
    text.setString("cac");
    text.setCharacterSize(56); // in pixels, not points!
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::Font font;
    font.loadFromFile("resources/fonts/arial.ttf");
    text.setFont(font);*/
    this->m_window.draw(this->m_text);
};

#endif