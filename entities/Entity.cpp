//
// Created by kienle on 13/02/2022.
//
#ifndef ZOFIA_ET_CPP__
#define ZOFIA_ET_CPP__
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#define ZOFIA zofia::
namespace zofia {
    class Entity {
        //private:
            //Entity properties
            //sf::Texture m_texture;
            //sf::Sprite m_sprite;

        protected:
            sf::RenderWindow& m_window;
        public:
             Entity(sf::RenderWindow& window) : m_window{window}{

            }
            //virtual ~Entity() = default;
            virtual void init() = 0;
            virtual void draw() = 0;
    };
}
#endif