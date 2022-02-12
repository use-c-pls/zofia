/* Author @daoluke */
#ifndef __ZOFIA_STOUT_LOGGING_CPP
#define __ZOFIA_STOUT_LOGGING_CPP
#include <spdlog/spdlog.h>
#include "Logging.cpp"

namespace zofia {
    class StoutLogging : public zofia::Logging {
        public:
          template<typename T>
          void debug(const T &msg) {
              spdlog::debug(msg);
          }

          template<typename T>
          void info(const T &msg) {
              spdlog::info(msg);
          }

          template<typename T>
          void warning(const T &msg) {
              spdlog::warn(msg);
          }

          template<typename T>
          void error(const T &msg) {
              spdlog::error(msg);
          }

          template<typename T>
          void critical(const T &msg) {
              spdlog::critical(msg);
          }
    };
}

#endif
