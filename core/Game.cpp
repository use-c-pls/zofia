/* Author @daoluke */
#ifndef ZOFIA_GAME_CPP__
#define ZOFIA_GAME_CPP__

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../include/game-states/full.hpp"
#include "audio/AudioManager.cpp"
#include "audio/Music.cpp"
#include "audio/SoundEffect.cpp"
#include "logging/Logger.cpp"
#include "Size.cpp"

namespace zofia {
    class Game {
        private:
          StateManager m_stateMachine;
          sf::RenderWindow m_window;

          void startEngine();

        public:
          explicit Game(Config config);

          virtual ~Game();

          void runWithState(std::unique_ptr<BaseState> state);

          void run();

          void runExample();
    };
}

sf::VideoMode createVideoMode(zofia::Size size) {
    return {static_cast<unsigned int>(size.getWidth()), static_cast<unsigned int>(size.getHeight())};
}

zofia::Game::Game(Config config) : m_stateMachine(config) {
    Size size(config.getWidth(), config.getHeight());
    m_window.create(createVideoMode(size), TITLE, sf::Style::Titlebar | sf::Style::Close);
    m_window.setFramerateLimit(120);
//    AudioManager::get().addAudio("explosion",zofia::make_unique<Wave>(ResourceHolder::get().sounds().get("explosion")));
//    AudioManager::get().getWave("explosion")->setVolume(50.f);
//    AudioManager::get().getWave("explosion")->setLoop(true);
//    AudioManager::get().getWave("explosion")->play();

//    sf::Sound sound;
//    sf::SoundBuffer soundBuffer;
//    soundBuffer.loadFromFile("resources/sounds/explosion.wav");
//    sound.setBuffer(soundBuffer);
//    sound.setVolume(100.f);
//    sound.setPitch(1.2f);
//    sound.setLoop(true);
//    sound.play();

//    sf::Music music;
//    if(!music.openFromFile("resources/sounds/background_music.ogg")){
//        LOG_DEBUG("Could not load music");
//    }
//    music.setVolume(50.f);
//    music.setLoop(true);
//    music.play();

}

zofia::Game::~Game() {
    LOG_INFO("Cleaning up and closing Game....");
}

void zofia::Game::startEngine() {
    //        float fps = 1.0f / (clock.restart().asSeconds());
//        LOG_DEBUG("FPS: {}", fps);

    constexpr unsigned TPS = 60; // ticks per seconds
    const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag = sf::Time::Zero;

    while (m_stateMachine.isRunning()) {

        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;
        lastTime = time;
        lag += elapsed;

        m_stateMachine.nextState();
        m_stateMachine.processEvents();
        m_stateMachine.update(elapsed);

        while (lag >= timePerUpdate) {
            ticks++;
            lag -= timePerUpdate;
            m_stateMachine.fixedUpdate(elapsed);
        }

        m_stateMachine.draw();
    }
}

void zofia::Game::runWithState(std::unique_ptr<BaseState> state) {
    m_stateMachine.run(std::move(state));
    this->startEngine();
}

void zofia::Game::runExample() {
    runWithState(zofia::StateFactory::build<MenuState>(m_stateMachine, m_window, true));
}

void zofia::Game::run() {
    runWithState(zofia::StateFactory::build<IntroState>(m_stateMachine, m_window, true));
}

#endif