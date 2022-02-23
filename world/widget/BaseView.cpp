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
          std::map<std::string, std::unique_ptr<DrawableEntity>> m_entities;

          void addEntity(std::string key, std::unique_ptr<DrawableEntity> entity) {
              this->m_entities.insert(std::make_pair(key, std::move(entity)));
          }

        public:
          BaseView() : DrawableEntity() {

          }

          explicit BaseView(std::string id) : m_id(std::move(id)), DrawableEntity() {};

          ~BaseView() override;

          virtual void update(T &context) = 0;

          void setId(std::string id) {
              m_id = std::move(id);
          }
    };

}


template<typename BaseViewContext>
zofia::BaseView<BaseViewContext>::~BaseView() {
    LOG_INFO("Destroying views `{}`", m_id);
    m_entities.clear();
}

#endif