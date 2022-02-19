//
// Created by kienle on 18/02/2022.
//

#ifndef ZOFIA_BASEVIEW_CPP
#define ZOFIA_BASEVIEW_CPP

#include "../core/logging/logging.hpp"
#include "../entities/base.hpp"

#include <utility>
#include <vector>

namespace zofia {
    class BaseViewContext {

    };

    template<typename BaseViewContext>
    class BaseView {
        private:
          std::string m_name{};
        protected:
          std::vector<Entity *> m_entities;

          void addEntity(Entity *entity) {
              this->m_entities.push_back(entity);
          }

        public:
          BaseView() = default;

          BaseView(std::string name) : m_name(std::move(name)) {};

          ~BaseView();

          virtual void draw() = 0;

          virtual void update(BaseViewContext &context) = 0;
    };

}


template<typename BaseViewContext>
zofia::BaseView<BaseViewContext>::~BaseView() {
    LOG_INFO("Destroying views `{}`", m_name);
    m_entities.clear();
}

#endif