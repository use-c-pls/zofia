/* Author @daoluke */
#include <iostream>

namespace zofia {
    class Greeting {
        public:
          static void greeting(const std::string name) {
              std::cout << "Hello, " + name + "!" << std::endl;
          }
    };
}