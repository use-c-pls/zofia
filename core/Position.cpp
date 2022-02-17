//
// Created by kienle on 17/02/2022.
//

#ifndef ZOFIA_POSITION_CPP__
#define ZOFIA_POSITION_CPP__

namespace zofia {
    class Position {
        private:
          int m_xAxis{0};
          int m_yAxis{0};
        public:
          Position(int x, int y) : m_xAxis(x), m_yAxis(y) {}

          int getXAxis() const{
              return this->m_xAxis;
          }

          int getYAxis() const{
              return this->m_yAxis;
          }
    };
}
#endif