/* Author @daoluke */
#ifndef ZOFIA_MENU_SCENE_CPP__
#define ZOFIA_MENU_SCENE_CPP__
#include "../core/Application.cpp"

namespace zofia {
    class MenuScene {
        private:
          zofia::Game *m_game;
        public:
          explicit MenuScene(zofia::Game *game) {
              this->m_game = game;
          }
    };
}

#endif