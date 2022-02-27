//
// Created by kienle on 26/02/2022.
//

#ifndef ZOFIA_AUDIO_MNG_CPP__
#define ZOFIA_AUDIO_MNG_CPP__

#include <SFML/Audio/SoundSource.hpp>
#include <map>
#include <memory>
#include <vector>

#include "SoundEffect.cpp"
#include "Music.cpp"

namespace zofia{
    class AudioManager{
        private:
          std::map<std::string,std::unique_ptr<sf::SoundSource>> m_audios;

        public:
          ~AudioManager() = default;
            void addAudio(std::string key,std::unique_ptr<sf::SoundSource> soundSource){
                m_audios.insert(std::make_pair(key,std::move(soundSource)));
            }

            static AudioManager &get(){
                static AudioManager m_manager;
                return m_manager;
            }

            Wave *getWave(std::string key){
                return dynamic_cast<Wave *>(m_audios[key].get());
            }

            Music *getMusic(std::string key){
                return dynamic_cast<Music*>(m_audios[key].get());
            }


    };
}

#endif