/* Author @daoluke */
#ifndef ZOFIA_SIZE_CPP__
#define ZOFIA_SIZE_CPP__

namespace zofia {
    class Size {
        private:
          int m_width{0};
          int m_height{0};
        public:
          Size(int width, int height) : m_width(width), m_height(height) {}
          int getWidth() const {
              return m_width;
          }
          int getHeight() const {
              return m_height;
          }
    };
}
#endif