/* Author @daoluke */
#ifndef ZOFIA_GREETING_CPP__
#define ZOFIA_GREETING_CPP__

#include <iostream>

namespace zofia {
    class Greeting {
        public:
          static void greeting(const std::string &name) {
              std::cout << "Hello, " + name + "!" << std::endl;
          }
    };
}

#endif