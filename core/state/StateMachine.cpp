/* Author @daoluke */
#ifndef ZOFIA_STATE_MANAGER_CPP__
#define ZOFIA_STATE_MANAGER_CPP__
#include <memory>
#include <stack>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../logging/logging.hpp"

#define ZOFIA zofia::
namespace zofia {
    class BaseState;
    class StateMachine;
    class BaseState {
        protected:
          zofia::StateMachine &m_manager;
          sf::RenderWindow &m_window;

          bool m_replacing;

          std::unique_ptr<BaseState> m_next;
        public:
          BaseState(zofia::StateMachine &stateManager, sf::RenderWindow &window, bool replace = true) :
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

    class StateMachine {
        private:
          std::stack<std::unique_ptr<zofia::BaseState>> m_states;
          bool m_resume;
          bool m_running;
        public:
          StateMachine();
          ~StateMachine();
          void run(std::unique_ptr<zofia::BaseState> state);

          void nextState();
          void lastState();

          void processEvents();
          void update();
          void draw();

          bool isRunning() const {
              return m_running;
          }

          void quit();
        private:
          void resumeIfNeeded();
    };
}


// --------------

ZOFIA StateMachine::StateMachine() : m_resume(false), m_running(true) {}

ZOFIA StateMachine::~StateMachine() {
    LOG_INFO("Cleaning up and closing StateMachine....");
    while (!m_states.empty()) {
        this->m_states.pop();
    }
}

void ZOFIA StateMachine::run(std::unique_ptr<BaseState> state) {
    m_running = true;
    m_states.push(std::move(state));
}

void ZOFIA StateMachine::nextState() {
    resumeIfNeeded();
    // There needs to be a state
    if (m_states.empty()) {
        return;
    }
    auto temp = m_states.top()->next();

    // Only change states if there's a next one existing
    if (temp == nullptr) {
        return;
    }
    // Replace the running state
    if (temp->isReplacing()) {
        m_states.pop();
    } else {
        // Pause the running state
        m_states.top()->pause();
    }

    m_states.push(std::move(temp));
}

void ZOFIA StateMachine::resumeIfNeeded() {
    if (this->m_resume) {
        // Cleanup the current state
        if (!m_states.empty()) {
            m_states.pop();
        }

        // Resume previous state
        if (!m_states.empty()) {
            m_states.top()->resume();
        }

        m_resume = false;
    }
}

void ZOFIA StateMachine::lastState() {
    m_resume = true;
}

void ZOFIA StateMachine::processEvents() {
    this->m_states.top()->processEvents();
}

void ZOFIA StateMachine::update() {
    // Let the state update the game
    m_states.top()->update();
}

void ZOFIA StateMachine::draw() {
    // Let the state draw the screen
    m_states.top()->draw();
}

void ZOFIA StateMachine::quit() {
    m_running = false;
}
#endif