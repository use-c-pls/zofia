//
// Created by kienle on 13/02/2022.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#define ZOFIA zofia::
namespace zofia {
    class Entity {
        private:
            //Entity properties
            sf::Texture m_texture;
            sf::Sprite m_sprite;
        public:
            explicit Entity(){
                this->init();
            }
            ~Entity();
            virtual void init();
            virtual void updateState();
            virtual void draw(sf::RenderWindow& window);
    };
}

/*
void ZOFIA Entity::init(){

}

void ZOFIA Entity::updateState() {

}

void ZOFIA Entity::draw(sf::RenderWindow& window){
}*/
