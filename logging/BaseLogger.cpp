/* Author @daoluke */
#ifndef __ZOFIA_LOGGING_CPP
#define __ZOFIA_LOGGING_CPP

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <algorithm>

#define ZOFIA zofia::

namespace zofia {
    class BaseLogger {
        private:
          std::shared_ptr<spdlog::logger> m_logger;
        public:
          BaseLogger() : BaseLogger("default") {
              info("Init default logging");
          };

          explicit BaseLogger(std::string name) {
              auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
              m_logger = std::make_shared<spdlog::logger>(name, sink);
              spdlog::initialize_logger(m_logger);
          }

          void changeLogLevel(std::string logLevel);

          template<typename... Args>
          void debug(const std::string fmt, Args &...args) {
              this->m_logger->debug(fmt, args...);
          }

          template<typename... Args>
          void info(const std::string fmt, Args &...args) {
              this->m_logger->info(fmt, args...);
          }

          template<typename... Args>
          void warn(const std::string fmt, Args &...args) {
              this->m_logger->warn(fmt, args...);
          }
          template<typename... Args>
          void error(const std::string fmt, Args &...args) {
              this->m_logger->error(fmt, args...);
          }

          template<typename... Args>
          void critical(const std::string fmt, Args &...args) {
              this->m_logger->critical(fmt, args...);
          }

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

#endif