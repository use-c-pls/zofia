//
// Created by kienle on 18/02/2022.
//

#ifndef ZOFIA_BASEVIEW_CPP
#define ZOFIA_BASEVIEW_CPP

#include <utility>
#include <map>

#include "../../include/core/logging.hpp"
#include "../DrawableEntity.cpp"

namespace zofia {

    template<typename T>
    class BaseView : public DrawableEntity {
        private:
          std::string m_id{};
        protected:
          std::map<std::string, DrawableEntity *> m_entities;

          void addEntity(std::string key, DrawableEntity *entity) {
              this->m_entities.insert(std::pair<std::string, DrawableEntity *>(key, entity));
          }

        public:
          BaseView() : DrawableEntity() {

          }

          explicit BaseView(std::string id) : m_id(std::move(id)), DrawableEntity() {};

          ~BaseView() override;

          virtual void update(T &context) = 0;
    };

}


template<typename BaseViewContext>
zofia::BaseView<BaseViewContext>::~BaseView() {
    LOG_INFO("Destroying views `{}`", m_id);
    for (const auto &it: m_entities) {
        delete (it.second);
    }
    m_entities.clear();
}

#endif