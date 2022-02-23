/* Author @daoluke */
#ifndef ZOFIA_LOGGING_CPP__
#define ZOFIA_LOGGING_CPP__

#include <memory>
#include <algorithm>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#define ZOFIA zofia::

namespace zofia {
    class BaseLogger {
        private:
          std::shared_ptr<spdlog::logger> m_logger;
        public:
          BaseLogger() : BaseLogger("default") {
              info("Init default logging");
          };

          explicit BaseLogger(std::string name);

          void changeLogLevel(std::string logLevel);

          template<typename... Args>
          void debug(std::string fmt, Args &...args);

          template<typename... Args>
          void info(std::string fmt, Args &...args);

          template<typename... Args>
          void warn(std::string fmt, Args &...args);

          template<typename... Args>
          void error(std::string fmt, Args &...args);

          template<typename... Args>
          void critical(std::string fmt, Args &...args);

        private:

    };
}

void ZOFIA BaseLogger::changeLogLevel(std::string logLevel) {
    if (logLevel.empty()) {
        logLevel = "info";
    }
    // to lower case
    std::for_each(logLevel.begin(), logLevel.end(), [](char &c) {
        c = ::tolower(c);
    });
    if (logLevel == "debug") {
        this->m_logger->set_level(spdlog::level::debug);
    } else if (logLevel == "info") {
        this->m_logger->set_level(spdlog::level::info);
    } else if (logLevel == "warning") {
        this->m_logger->set_level(spdlog::level::warn);
    } else if (logLevel == "error") {
        this->m_logger->set_level(spdlog::level::err);
    } else if (logLevel == "critical") {
        this->m_logger->set_level(spdlog::level::critical);
    }
}

zofia::BaseLogger::BaseLogger(std::string name) {
    auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    m_logger = std::make_shared<spdlog::logger>(name, sink);
    spdlog::initialize_logger(m_logger);
}

template<typename... Args>
void zofia::BaseLogger::debug(const std::string fmt, Args &... args) {
    this->m_logger->debug(fmt, args...);
}

template<typename... Args>
void zofia::BaseLogger::info(const std::string fmt, Args &... args) {
    this->m_logger->info(fmt, args...);
}

template<typename... Args>
void zofia::BaseLogger::warn(const std::string fmt, Args &... args) {
    this->m_logger->warn(fmt, args...);
}

template<typename... Args>
void zofia::BaseLogger::error(const std::string fmt, Args &... args) {
    this->m_logger->error(fmt, args...);
}

template<typename... Args>
void zofia::BaseLogger::critical(const std::string fmt, Args &... args) {
    this->m_logger->critical(fmt, args...);
}

#endif