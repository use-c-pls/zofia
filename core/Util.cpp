/* Author @daoluke */
#ifndef ZOFIA_UTIL_CPP__
#define ZOFIA_UTIL_CPP__

#include <memory>
#include "logging/Logger.cpp"

namespace zofia {

    template<typename T, typename... Args>
    static std::unique_ptr<T> make_unique(Args &&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template<typename T, typename... Args>
    static std::unique_ptr<T> build(Args &&... args) {
        auto val = std::unique_ptr<T>{nullptr};

        try {
            val = std::unique_ptr<T>(new T(std::forward<Args>(args)...));
        } catch (std::runtime_error &exception) {
            LOG_ERROR("Error while building stuff");
            LOG_ERROR(exception.what());
        }
        return val;
    }
}

#endif