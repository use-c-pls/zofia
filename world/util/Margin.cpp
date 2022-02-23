/* Author @daoluke */

#ifndef ZOFIA_MARGIN_CPP__
#define ZOFIA_MARGIN_CPP__

namespace zofia {
    struct Margin {
        enum {
            TOP = 1, BOTTOM = 2, LEFT = 3, RIGHT = 4
        };
    };

    class MarginInfo {
        public:
          int type{-1};
          float value{-1};

          MarginInfo() = default;

          MarginInfo(int type, float value) : type(type), value(value) {

          }

          bool usePlus() {
              return type == Margin::TOP || type == Margin::LEFT;
          }
    };
}

#endif