//
// Created by kienle on 26/02/2022.
//

#ifndef ZOFIA_MUSIC_CPP__
#define ZOFIA_MUSIC_CPP__

#include <SFML/Audio/Music.hpp>

namespace zofia {
    class Music : public sf::Music{
        private:
        public:
          Music(std::string path) : sf::Music(){
              this->openFromFile(path);
          }
          ~Music() = default;
    };
}

#endif