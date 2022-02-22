//
// Created by kienle on 18/02/2022.
//

#ifndef ZOFIA_BASEVIEW_CPP
#define ZOFIA_BASEVIEW_CPP

#include "../include/core/logging.hpp"
#include "../include/entities/base.hpp"

#include <utility>
#include <map>

namespace zofia {
    class BaseViewContext {

    };

    template<typename T>
    class BaseView {
        private:
          std::string m_id{};
        protected:
          std::map<std::string, Entity *> m_entities;

          void addEntity(std::string key, Entity *entity) {
              this->m_entities.insert(std::pair<std::string, Entity *>(key, entity));
          }

        public:
          BaseView() = default;

          explicit BaseView(std::string id) : m_id(std::move(id)) {};

          ~BaseView();

          virtual void draw() = 0;

          virtual void update(T &context) = 0;
    };

}


template<typename BaseViewContext>
zofia::BaseView<BaseViewContext>::~BaseView() {
    LOG_INFO("Destroying views `{}`", m_id);
    for (const auto& it : m_entities) {
        delete (it.second);
    }
    m_entities.clear();
}

#endif