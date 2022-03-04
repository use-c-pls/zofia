//
// Created by kienle on 26/02/2022.
//

#ifndef ZOFIA_WAVE_CPP__
#define ZOFIA_WAVE_CPP__

#include <string>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "../logging/Logger.cpp"

namespace zofia {
    class Wave : public sf::Sound {
        private:
        public:
          Wave(std::string path) : sf::Sound() {
              sf::SoundBuffer m_soundBuffer{};
              m_soundBuffer.loadFromFile(path);
              this->setBuffer(m_soundBuffer);
          }

          Wave(sf::SoundBuffer &buffer) : sf::Sound(buffer) {
//                LOG_DEBUG("Name cc");
//
//                this->setBuffer(buffer);
          }

          ~Wave() = default;
    };
}
#endif