/* Author @daoluke */

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
