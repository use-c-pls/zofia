/* Author @daoluke */
#ifndef __ZOFIA_LOGGING_CPP
#define __ZOFIA_LOGGING_CPP

#include <spdlog/spdlog.h>

#define ZOFIA zofia::

namespace zofia {
    class Logging {
        public:
          Logging();
          void changeLogLevel(std::string logLevel);
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
        private:
          void _();
    };
}

ZOFIA Logging::Logging() {
    _();
}

void ZOFIA Logging::changeLogLevel(std::string logLevel) {
    if (logLevel.empty()) {
        logLevel = "info";
    }
    // to lower case
    std::for_each(logLevel.begin(), logLevel.end(), [](char & c){
        c = ::tolower(c);
    });
    if (logLevel == "debug") {
        spdlog::set_level(spdlog::level::debug);
    } else if (logLevel == "info") {
        spdlog::set_level(spdlog::level::info);

    } else if (logLevel == "warning") {
        spdlog::set_level(spdlog::level::warn);

    } else if (logLevel == "error") {
        spdlog::set_level(spdlog::level::err);
    } else if (logLevel == "critical") {
        spdlog::set_level(spdlog::level::critical);
    }
}

void ZOFIA Logging::_() {
    spdlog::info("Using level `info` as default level");
}
#endif