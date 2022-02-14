//
// Created by kienle on 14/02/2022.
//
#include "Entity.cpp"

#define ZOFIA zofia::
namespace zofia {
    class Typography : public Entity{
        private:
            sf::Text m_text;
        public:
            explicit Typography() : Entity() {
                Entity::init();
            }
            explicit Typography(const std::string& fontPath) : Entity(){
                Entity::init();
                setFontFromStream(fontPath);
            }
            void draw(sf::RenderWindow& window);
            void init() override;
            sf::Text getText(){
                return this->m_text;
            }
            void setFontFromStream(const std::string& path);
    };
}

void zofia::Typography::init(){
    //Nothing to initialize
    this->m_text.setString("Hello world");

// set the character size
    this->m_text.setCharacterSize(24); // in pixels, not points!

// set the color
    this->m_text.setFillColor(sf::Color::Red);

}

void zofia::Typography::setFontFromStream(const std::string& path) {
    sf::FileInputStream stream;
    stream.open(path);
    sf::Font font;
    if(!font.loadFromStream(stream)){
        //Couldn't load from the path check path exist or not
    }else{
        this->m_text.setFont(font);
    }
}

void zofia::Typography::draw(sf::RenderWindow& window){
    window.draw(this->m_text);
};