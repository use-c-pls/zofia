/* Author @daoluke */
#ifndef ZOFIA_RESOURCE_HOLDER_CPP__
#define ZOFIA_RESOURCE_HOLDER_CPP__

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "ResourceManager.cpp"

namespace zofia {
    class ResourceHolder {
        private:

          ResourceManager<sf::Font> m_fonts;
          ResourceManager<sf::Texture> m_backgrounds;
          ResourceManager<sf::Texture> m_views;
          ResourceManager<sf::SoundBuffer> m_sounds;

          ResourceHolder() :
                  m_fonts("font", "resources/fonts", "ttf"),
                  m_backgrounds("background", "resources/backgrounds", "png"),
                  m_views("view", "resources/views", "png"),
                  m_sounds("sound", "resources/sound", "oog") {}

        public:
          static ResourceHolder &get() {
              static ResourceHolder holder;
              return holder;
          }

          ResourceManager<sf::Font> fonts() {
              return m_fonts;
          }

          ResourceManager<sf::Texture> backgrounds() {
              return m_backgrounds;
          }

          ResourceManager<sf::Texture> views() {
              return m_views;
          }

          ResourceManager<sf::SoundBuffer> sounds() {
              return m_sounds;
          }

          ~ResourceHolder() {
              fonts().clear();
              backgrounds().clear();
              views().clear();
              sounds().clear();
          }
    };
}

#endif