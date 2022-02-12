/* Author @daoluke */
#ifndef __ZOFIA_LOGGING_CPP
#define __ZOFIA_LOGGING_CPP

#include <set>
#include <spdlog/spdlog.h>

#define ZOFIA zofia::

namespace zofia {
    class Logging {
        protected:
          Logging();
        public:
          void changeLogLevel(std::string logLevel);
        private:
          void _();
    };
}

ZOFIA Logging::Logging() {
    _();
}

void toLowerCase(std::string s);

void ZOFIA Logging::changeLogLevel(std::string logLevel) {
    if (logLevel.empty()) {
        logLevel = "info";
    }
    // to lower case
    //std::transform(logLevel.begin(), logLevel.end(), logLevel.begin(), [](unsigned char c) { return std::tolower(c); });
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