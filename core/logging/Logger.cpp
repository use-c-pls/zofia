/* Author @daoluke */
#ifndef ZOFIA_LOGGER_HEADER_CPP__
#define ZOFIA_LOGGER_HEADER_CPP__

#include "BaseLogger.cpp"

#define LOG_DEBUG(args...) CORE_LOGGER.debug(args)
#define LOG_INFO(args...) CORE_LOGGER.info(args)
#define LOG_WARN(args...) CORE_LOGGER.warn(args)
#define LOG_ERROR(args...) CORE_LOGGER.error(args)
#define LOG_CRITICAL(args...) CORE_LOGGER.critical(args)

namespace zofia {
    static BaseLogger CORE_LOGGER("Core");
}
#endif
