/* Author @daoluke */
#ifndef ZOFIA_RESOURCE_MANAGER_CPP__
#define ZOFIA_RESOURCE_MANAGER_CPP__

#include <string>
#include <utility>
#include <unordered_map>

#include "../../include/core/logging.hpp"

namespace zofia {
    template<typename Resource>
    class ResourceManager {
        private:
          const std::string m_name;
          const std::string m_folder;
          const std::string m_extension;

          std::unordered_map<std::string, Resource> m_resources;
        public:
          ResourceManager(std::string name, std::string folder, std::string extension)
                  : m_name(std::move(name)),
                    m_folder(std::move(folder)),
                    m_extension(std::move(extension)) {
          }

          virtual ~ResourceManager() = default;

          void add(const std::string &name) {
              Resource r;
              std::string fullFileName = getFullFileName(name);
              if (r.loadFromFile(fullFileName)) {
                  m_resources.insert(std::make_pair(name, r));
                  return;
              }
              LOG_CRITICAL("Resource {} with name `{}` is not found", m_name, name);
          }

          bool exists(const std::string &name) {
              return m_resources.find(name) != m_resources.end();
          }

          const Resource &get(const std::string &name) {
              if (!exists(name)) {
                  add(name);
              }
              return m_resources.at(name);
          }

          void remove(const std::string &name) {
              if (exists(name)) {
                  m_resources.erase(name);
              }
          }

          void clear() {
              LOG_INFO("Resource `{}` is destroying...", m_name);
              m_resources.clear();
          }

          std::string getName() const {
              return m_name;
          }

        private:
          std::string getFullFileName(const std::string &name) {
              return m_folder + "/" + name + "." + m_extension;
          }
    };
}

#endif