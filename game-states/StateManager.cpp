/* Author @daoluke */
#ifndef ZOFIA_STATE_MANAGER_CPP__
#define ZOFIA_STATE_MANAGER_CPP__

#include <memory>
#include <stack>

#include "../core/config/config.hpp"
#include "../core/logging/logging.hpp"

#include "BaseState.cpp"

#define ZOFIA zofia::
namespace zofia {
    class BaseState;

    class StateManager;

    class StateManager {
        private:
          Config &m_config;
          std::stack<std::unique_ptr<zofia::BaseState>> m_states;
          bool m_resume;
          bool m_running;
        public:
          explicit StateManager(Config &config) : m_resume(false), m_running(true), m_config(config) {};

          ~StateManager();

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

ZOFIA StateManager::~StateManager() {
    LOG_INFO("Cleaning up and closing StateMachine....");
    while (!m_states.empty()) {
        this->m_states.pop();
    }
}

void ZOFIA StateManager::run(std::unique_ptr<BaseState> state) {
    m_running = true;
    m_states.push(std::move(state));
}

void ZOFIA StateManager::nextState() {
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

void ZOFIA StateManager::resumeIfNeeded() {
    if (!this->m_resume) return;
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

void ZOFIA StateManager::lastState() {
    m_resume = true;
}

void ZOFIA StateManager::processEvents() {
    this->m_states.top()->processEvents();
}

void ZOFIA StateManager::update() {
    m_states.top()->update();
}

void ZOFIA StateManager::draw() {
    m_states.top()->draw();
}

void ZOFIA StateManager::quit() {
    m_running = false;
}

#endif