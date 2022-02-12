/* Author @daoluke */
#ifndef ZOFIA_MENU_SCENE_CPP__
#define ZOFIA_MENU_SCENE_CPP__
#include "../core/Game.cpp"

namespace zofia {
    class MenuScene {
        private:
          Size m_size;
          zofia::Game *m_game;
        public:
          explicit MenuScene(zofia::Game *game) : m_size(game->getSize().getWidth(), game->getSize().getHeight()) {
              this->m_game = game;
              std::cout << "Address Game 2 #" << this->m_game << std::endl;
          }
    };
}

#endif