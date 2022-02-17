/* Author @daoluke */
#ifndef ZOFIA_BASE_STATE_CPP__
#define ZOFIA_BASE_STATE_CPP__

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#define ZOFIA zofia::
namespace zofia {
    class BaseState;
    class StateManager;

    class BaseState {
        protected:
          zofia::StateManager &m_manager;
          sf::RenderWindow &m_window;

          bool m_replacing;

          std::unique_ptr<BaseState> m_next;
        public:
          BaseState(zofia::StateManager &stateManager, sf::RenderWindow &window, bool replace = true) :
                  m_manager{stateManager}, m_window{window}, m_replacing{replace} {
          }

          virtual ~BaseState() = default;

          BaseState(const BaseState &) = delete;

          BaseState &operator=(const BaseState &) = delete;

          virtual void pause() = 0;

          virtual void resume() = 0;

          virtual void processEvents() = 0;

          virtual void update() = 0;

          virtual void draw() = 0;

          std::unique_ptr<BaseState> next() {
              return std::move(m_next);
          }

          bool isReplacing() const {
              return m_replacing;
          };
    };
}
#endif