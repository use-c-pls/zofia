//
// Created by kienle on 18/02/2022.
//

#ifndef ZOFIA_BASEVIEW_CPP
#define ZOFIA_BASEVIEW_CPP

#include "../entities/base.hpp"

#include <vector>

namespace zofia{
    class BaseViewContext{

    };
    template<typename BaseViewContext>
    class BaseView{
        private:
          std::vector<std::unique_ptr<zofia::Entity>> m_entities;
//          std::vector<Entity<EntityContext>*> m_entities;
        protected:
          void addEntity(Entity entity){
              auto x = make_unique<Entity>(entity);
              this->m_entities.push(x);
          }
          template<typename T, typename... Args>
          std::unique_ptr<T> make_unique(Args &&... args) {
              return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
          }
        public:
          BaseView();
          ~BaseView(){
              while(!this->m_entities.empty()){
                  this->m_entities.pop_back();
              }
          }



          virtual void draw() = 0;

          virtual void update(BaseViewContext &context) = 0;
    };
}
#endif